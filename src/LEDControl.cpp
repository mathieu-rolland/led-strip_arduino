#include "LEDControl.h"

/**********************************************/
void setupLEDControl(){
  pinMode( GREEN_LIGHT , OUTPUT);
  pinMode( RED_LIGHT , OUTPUT);
  pinMode( BLUE_LIGHT , OUTPUT);

  pinMode( ENABLE1_2 , OUTPUT);
  pinMode( ENABLE3_4 , OUTPUT);

  digitalWrite( ENABLE1_2 , HIGH);
  digitalWrite( ENABLE3_4 , HIGH);
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

void disableAll(){
  switchOffLight( GREEN_LIGHT );
  switchOffLight( BLUE_LIGHT );
  switchOffLight( RED_LIGHT );
}

void switchOnWithFade( int light , int intensity, int threshold, int time){

  for( int i = MIN_INTENSITY ; i > intensity ; i-- ){
    analogWrite( light , i );
    delay(time);
  }

}
