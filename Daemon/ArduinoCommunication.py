__author__ = 'MaikBook'


import serial
from States import States

class ArduinoCommunication:

    def __init__(self, port, baudrate):
        self.port = port
        self.baudrate = baudrate

        self.ser = serial.Serial(self.port, self.baudrate)
        self.state = None

    def receive(self):
        if self.ser.inWaiting():
            message = self.ser.readline()
            self.setstate(message)
            print "Message Received: " + message

    def send(self, message):
        self.ser.write(message)
        print "Message Sended: " + message

    def setstate(self, message):
        if States.TIME_RUNNING in message:
            self.state = States.TIME_RUNNING
        elif States.TIME_STOPPED in message:
            self.state = States.TIME_STOPPED

    def getstate(self):
        return self.state


