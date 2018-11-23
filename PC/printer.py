from serial import Serial
from serial.tools import list_ports

class Printer:
    def __init__(self, port='/dev/ttyACM0', baudrate=9600):
        self.port, self.baudrate = port, baudrate
        self.serial = Serial(self.port, self.baudrate)

    def __del__(self):
        self.serial.close()

    def _send_command(self, cmd, param):
        if param > 0x7FF or param < -0x800:
            raise ValueError

        if param < 0: param = 0x1000 + param

        self.serial.write(
            ((param << 4) | cmd).to_bytes(2, byteorder='little'))

    @classmethod
    def list_ports(cls):
        """List the COM ports."""
        return [port.device for port in list_ports.comports()]

    def set_encoder_pins(self, pins):
        """Set the encoder pins.
        
        Positional arguments:
        pins -- an integer between 0 and 7 (inclusive), representing the pins in the encoder
        """

        if not isinstance(pins, int) or pins < 0 or pins > 7:
            raise ValueError
        self._send_command(0, pins)

    def move_encoder_carriage_relative(self, delta):
        """If delta is positive, move delta millimeters to the right. If delta 
        is negative, move delta millimeters to the left."""

        if delta < -400 or delta > 400: raise ValueError
        self._send_command(1, int(delta * 10))
