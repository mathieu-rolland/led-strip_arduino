#include "soundControl.h"

/**********************************************/
long previousTime;
long actualTime;

/**********************************************/

void initSound(){
  pinMode( GREEN_LIGHT , OUTPUT);
  pinMode( RED_LIGHT , OUTPUT);
  pinMode( BLUE_LIGHT , OUTPUT);

  pinMode( ENABLE1_2 , OUTPUT);
  pinMode( ENABLE3_4 , OUTPUT);

  pinMode( MICRO_THRESHOLD , INPUT );

  digitalWrite( ENABLE1_2 , HIGH);
  digitalWrite( ENABLE3_4 , HIGH);

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

/**********************************************/
void switchOnLight( int light ){
  for(int i = 0 ; i < 255; i = i + 10 ){
    analogWrite( light , 255 - i );
    delay(5);
  }
}

void switchOnLight( int light , int intensity){
    analogWrite( light , intensity );
}

void switchOffLight( int light ){
    digitalWrite( light , HIGH );
}
