from serial import Serial

class Printer:
    def __init__(self, port='/dev/ttyACM0', baudrate=9600):
        self.port, self.baudrate = port, baudrate
        self.serial = Serial(self.port, self.baudrate)

    def _send_command(self, cmd, param):
        self.serial.write(
            ((param << 4) | cmd).to_bytes(2, byteorder='little'))

