
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

void initSound();
void displayUsingSound();
void switchOnLight(int light);
void switchOnLight(int light , int intensity);
void switchOffLight( int light );
