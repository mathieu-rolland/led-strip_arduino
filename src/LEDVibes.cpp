#include "LEDVibes.h"

int intensity = MIN_INTENSITY;
int color[3] = {0,0,0};
int translationColor[3] = { RED_LIGHT , GREEN_LIGHT , BLUE_LIGHT };

unsigned int currentColor = 0;

void setupVibes(){
    pinMode( COLOR_CHANGE , INPUT );
    disableAll();
}

void vibes(){

  intensity = analogRead( INPUT_INTENSITY );
  intensity = map(intensity, 0, 1024, MIN_INTENSITY, MAX_INTENSITY);

  long actualTime = millis();

  if( digitalRead( COLOR_CHANGE )  == 1 ){

    Serial.print("[Color change] Current color :  ");
    Serial.print( currentColor );
    Serial.print( "pass to " );

    if( color[currentColor] == 1){
      color[currentColor] = 0 ;
      switchOffLight( translationColor[currentColor] );
      Serial.print( "0 " );
    }
    else{
      color[currentColor] = 1;
      switchOnWithFade( translationColor[currentColor] , intensity, 1, 10);
      Serial.print( "1 " );
    }

    currentColor ++;
    if( currentColor > 2 ) currentColor = 0;

  }

  Serial.print( " / intensity = " );
  Serial.print(intensity);

  Serial.print("Wait for : ");
  Serial.println( 100 - (millis() - actualTime) );

  for(int i = 0 ; i < 3 ; i++ ){
    if( color[i] == 1 ){
      switchOnLight( translationColor[i] , intensity );
    }
  }

  delay( 100 );

}
