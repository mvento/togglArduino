#pragma once

namespace TogglArduino {
  class Communicator {
  public:
    virtual void setRunningState() = 0;
    virtual void setStoppedState() = 0;
    virtual void setErrorState() = 0;
  };
}
