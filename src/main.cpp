
#include "arduino.h"
#include "LEDControl.h"
#include "soundControl.h"
#include "LEDVibes.h"

#define PIN_MODE_CHANGE 10

int mode = MODE_VIBES;

void setup(){

  Serial.begin(9600);

  /*Init master control*/
  pinMode( PIN_MODE_CHANGE , INPUT );

  /*LED Controller*/
  setupLEDControl();

  /*Init all components*/
  initSound();
  setupVibes();

}

void manageMode(){

  if( digitalRead( PIN_MODE_CHANGE ) == HIGH ){
    mode++;
    if( mode > 2 ){
      mode = 1;
    }
    delay(100);
    Serial.print("Change mode");
  }

}

void loop(){

  manageMode();

  if( mode == MODE_SOUND_CONTROL )  displayUsingSound();
  if( mode == MODE_VIBES ) vibes();

}
