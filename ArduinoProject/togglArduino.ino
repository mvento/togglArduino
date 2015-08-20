#include "Toggl.h"
#include "ArduinoCommunicator.h"

#define GREEN_PIN 7
#define RED_PIN 8
#define BAUD_RATE 9600

Toggl toggl( new TogglArduino::ArduinoCommunicator(GREEN_PIN, RED_PIN) );

void setup() {
  Serial.begin( BAUD_RATE );
  while (!Serial) {;}
}

void loop() {
  String input = Serial.readStringUntil( '\n' );

  if ( input.length() > 0 ) {
    toggl.doCycle( input );
  }

  delay( 1000 );
}
