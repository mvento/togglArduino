__author__ = 'MaikBook'

from TogglEntry import TogglEntry
from TogglPy import TogglPy

from States import States


class TogglCommunication:
    def __init__(self, pid, apikey = None):
        if not apikey:
            #         TODO: LOAD APIKEY FROM CONFIG FILE
            pass
        self.toggl = TogglPy.Toggl()
        self.toggl.setAPIKey(apikey)
        self.pid = pid
        self.entry = TogglEntry(self.pid, self.toggl)
        self.state = None

    def update(self):
        self.entry.updatefromcurrent()
        if self.isrunning():
            self.state = States.TIME_RUNNING
        else:
            self.state = States.TIME_STOPPED

    def run(self):
        if not self.isrunning():
            self.entry.start()
            self.state = States.TIME_RUNNING

    def stop(self):
        if self.isrunning():
            self.entry.stop()
            self.state = States.TIME_STOPPED

    def isrunning(self):
        return self.entry.isinitied()

    def getstate(self):
        return self.state
