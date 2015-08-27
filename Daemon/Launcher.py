from TogglCommunication import TogglCommunication
from ArduinoCommunication import ArduinoCommunication

toggl = TogglCommunication(10959693, "6445387bd9118535231e058263600c01")
arduino = ArduinoCommunication('/dev/cu.usbserial-A9007LUc', 115200)

from States import States

while True:
    toggl.update()
    arduino.receive()

    if arduino.getstate() == States.TIME_RUNNING:
        toggl.run()
    elif arduino.getstate() == States.TIME_STOPPED:
        toggl.stop()

    arduino.send(toggl.getstate())

