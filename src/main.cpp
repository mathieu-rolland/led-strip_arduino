
#include "arduino.h"
#include "soundControl.h"


void setup(){

  Serial.begin(9600);
  initSound();

}

void loop(){

  displayUsingSound();

}
