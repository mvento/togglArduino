#pragma once

#include "Communicator.h"
#include <Arduino.h>

namespace TogglArduino {
  class ArduinoCommunicator : public Communicator {

  protected:
    int greenLedPin;
    int redLedPin;

    void initPinnes();

    public:
      ArduinoCommunicator( int greenLedPin, int redLedPin );

      void setRunningState();
      void setStoppedState();
      void setErrorState();
  };
}
