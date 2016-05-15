#include "soundControl.h"

/**********************************************/
long previousTime;
long actualTime;

/**********************************************/
void initSound(){

  pinMode( MICRO_THRESHOLD , INPUT );

  previousTime = millis();
  actualTime = millis();
}

void displayUsingSound(){

  /*  digitalWrite( GREEN_LIGHT , HIGH );
    digitalWrite( RED_LIGHT  , HIGH );
    digitalWrite( BLUE_LIGHT , LOW );
  */

    actualTime = millis();

    switchOnLight( BLUE_LIGHT , 245 );
    switchOffLight( RED_LIGHT );
    switchOffLight( GREEN_LIGHT );

    if( digitalRead( MICRO_THRESHOLD ) == 1 ){


      Serial.print("Diff actualTime - previousTime = ");
      Serial.println(actualTime - previousTime);

      switchOnLight( GREEN_LIGHT , 245 );

      if( actualTime - previousTime < 2 * THRESHOLD ){
        switchOnLight( GREEN_LIGHT );
      }

      if( actualTime - previousTime < THRESHOLD ){
        switchOnLight( RED_LIGHT );
        switchOffLight( BLUE_LIGHT );
      }

      previousTime = millis();

    }

    delay( THRESHOLD / 4 );

}
