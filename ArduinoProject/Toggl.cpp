#include "Toggl.h"

Toggl::Toggl( TogglArduino::Communicator *oCommunicator ) {
  this->oCommunicator = oCommunicator;
}

unsigned int Toggl::parseInput( String input ) {
  if ( input == "RUNNING" ) {
    return Toggl::TIME_RUNNING;
  }
  else if ( input == "STOPPED" ) {
    return Toggl::TIME_STOPPED;
  }
  else {
    return Toggl::ERROR_OCCURRED;
  }
}

unsigned int Toggl::getState() {
  return this->currentState;
}

void Toggl::doCycle( String input ) {
  this->currentState = parseInput( input );

  if ( this->currentState == Toggl::TIME_RUNNING ) {
    this->oCommunicator->setRunningState();
  }
  else if ( this->currentState == Toggl::TIME_STOPPED ) {
    this->oCommunicator->setStoppedState();
  }
  else {
    this->oCommunicator->setErrorState();
  }
}
