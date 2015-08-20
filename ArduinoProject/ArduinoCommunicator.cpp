#include "ArduinoCommunicator.h"

TogglArduino::ArduinoCommunicator::ArduinoCommunicator( int greenLedPin, int redLedPin ) {
  this->greenLedPin = greenLedPin;
  this->redLedPin = redLedPin;

  this->initPinnes();
}

void TogglArduino::ArduinoCommunicator::setRunningState() {
  digitalWrite( this->greenLedPin, HIGH );
  digitalWrite( this->redLedPin, LOW );
}

void TogglArduino::ArduinoCommunicator::setStoppedState() {
  digitalWrite( this->greenLedPin, LOW );
  digitalWrite( this->redLedPin, HIGH );
}

void TogglArduino::ArduinoCommunicator::setErrorState() {
  digitalWrite( this->greenLedPin, HIGH );
  digitalWrite( this->redLedPin, HIGH );
}

void TogglArduino::ArduinoCommunicator::initPinnes() {
  pinMode( this->greenLedPin, OUTPUT );
  pinMode( this->redLedPin, OUTPUT );
}
