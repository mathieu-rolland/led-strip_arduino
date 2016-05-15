
#include "arduino.h"

const int OUT_GREEN = 3;
const int OUT_RED = 5;
const int OUT_BLUE = 6;

const int DEBUG_OUTPUT = 13;
const int MICRO_INPUT = A0;
const int MICRO_THRESHOLD = 8;

const int LED_SIGNAL = 2;

void setup()
{

  Serial.begin( 9600 );

  pinMode( OUT_GREEN , OUTPUT );
  analogWrite( OUT_GREEN , 0 );

  pinMode( OUT_RED , OUTPUT );
  analogWrite( OUT_RED , 0 );

  pinMode( OUT_BLUE, OUTPUT );
  analogWrite( OUT_BLUE , 0);

  //pinMode( MICRO_INPUT , INPUT );
  pinMode( MICRO_THRESHOLD , INPUT );

  pinMode( LED_SIGNAL , OUTPUT );
  digitalWrite(  LED_SIGNAL, LOW );

  pinMode ( DEBUG_OUTPUT , OUTPUT );

  digitalWrite( DEBUG_OUTPUT , HIGH );
  delay( 100 );
  digitalWrite( DEBUG_OUTPUT,  LOW );
  delay( 100 );
  digitalWrite( DEBUG_OUTPUT , HIGH );
  delay( 100 );
  digitalWrite( DEBUG_OUTPUT,  LOW );
  delay( 100 );

}

void loop()
{
  int microValue = analogRead( MICRO_INPUT );

  int threshodValue = digitalRead( MICRO_THRESHOLD );


  if( threshodValue == HIGH ){
    digitalWrite( LED_SIGNAL , HIGH );

     Serial.print ("Micro readed value : ");
     Serial.print( microValue );
     Serial.print( ", Threshold value : " );
 //delay( microValue );
     Serial.print( " => write Value : " );
     Serial.println( analogRead(MICRO_THRESHOLD) - microValue );
     Serial.print( analogRead(MICRO_THRESHOLD) );
  }else{
    digitalWrite(LED_SIGNAL , LOW );
    
  }


  /*for(int i = 0 ; i < 255 ; i++ ){
      analogWrite( OUT_GREEN , i  );
  }

  for(int i = 0 ; i < 255 ; i++ ){
      analogWrite( OUT_RED , i  );
  }

  for(int i = 0 ; i < 255 ; i++ ){
      analogWrite( OUT_BLUE , i  );
  }

  digitalWrite( OUT_GREEN ,  HIGH );
  */
//delay( 50 );
}
