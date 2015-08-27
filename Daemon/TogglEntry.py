__author__ = 'MaikBook'


class TogglEntry:
    def __init__(self, pid, toggl):
        self.pid = pid
        self.toggl = toggl
        self.data = None

    def updatefromcurrent(self):
        self.data = self.toggl.currentRunningTimeEntry()
        if not self.data['data']:
            self.data = None

    def start(self, message="NOMESSAGE"):
        self.data = self.toggl.startTimeEntry(message, self.pid)

    def stop(self):
        if self.isinitied():
            self.toggl.stopTimeEntry(self.getid())

    def getid(self):
        if self.data:
            return self.data['data']['id']
        else:
            return None

    def isinitied(self):
        if self.data:
            return True
        else:
            return False

