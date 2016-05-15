
#include "arduino.h"

/***********************************************/
#define ENABLE1_2 7
#define ENABLE3_4 8

/**********************************************/
#define GREEN_LIGHT 3
#define RED_LIGHT 5
#define BLUE_LIGHT 6
#define MICRO_THRESHOLD 2

/**********************************************/
#define DEBUG_LED 13
#define THRESHOLD 50


/**********************************************/
long previousTime;
long actualTime;

/**********************************************/
void setup(){

  Serial.begin(9600);

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


void loop(){

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
      delay(5);
    }

    previousTime = millis();

  }

  delay( THRESHOLD / 2 );

}
