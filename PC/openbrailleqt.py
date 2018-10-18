#!/usr/bin/env python3

import sys
import os.path
from PyQt5.QtWidgets import QMainWindow, QApplication, QFileDialog
import main_window

class OpenBrailleQt(QMainWindow, main_window.Ui_MainWindow):
    def __init__(self):
        super(self.__class__, self).__init__()

        self.current_file = None

        self.setupUi(self)
        self.actionNew.triggered.connect(self.new_file)
        self.actionOpen.triggered.connect(self.open_file)
        self.actionSave.triggered.connect(self.save_file)
        self.actionPrint.triggered.connect(self.send_to_printer)

    def send_to_printer(self):
        print(self.textEdit.toPlainText())

    def new_file(self):
        self.current_file = None
        self.textEdit.setText('')

    def open_file(self):
        # options = QFileDialog.Options() #| QFileDialog.DontUseNativeDialog
        file_path, _ = QFileDialog.getOpenFileName(self)

        if os.path.isfile(file_path):
            self.current_file = file_path
            with open(self.current_file, 'r') as f:
                self.textEdit.setText(f.read())

    def save_file(self):
        if self.current_file == None:
            self.save_as_file()
        else:
            with open(self.current_file, 'w') as f:
                f.write(self.textEdit.toPlainText())

    def save_as_file(self):
        self.current_file, _ = QFileDialog.getSaveFileName(self)
        
        with open(self.current_file, 'w') as f:
            f.write(self.textEdit.toPlainText())


if __name__ == '__main__':
    app = QApplication(sys.argv)
    open_braille_qt = OpenBrailleQt()
    open_braille_qt.show()
    app.exec()

