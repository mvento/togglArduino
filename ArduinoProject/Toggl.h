#pragma once

#include "Communicator.h"
#include <Arduino.h>

class Toggl {
  protected:
    int currentState;
    TogglArduino::Communicator *oCommunicator;

  public:

    static const unsigned int TIME_RUNNING = 1;
    static const unsigned int TIME_STOPPED = 2;
    static const unsigned int ERROR_OCCURRED = 3;

    Toggl( TogglArduino::Communicator *oCommunicator );

    unsigned int parseInput( String input );
    unsigned int getState();
    void doCycle( String input );
};
