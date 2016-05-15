#include "arduino.h"

/***********************************************/
#define ENABLE1_2 7
#define ENABLE3_4 8

/**********************************************/
#define GREEN_LIGHT 3
#define RED_LIGHT 5
#define BLUE_LIGHT 6

/**********************************************/
#define MAX_INTENSITY 0
#define MIN_INTENSITY 255

/**********************************************/
void setupLEDControl();
void switchOnLight( int light );
void switchOnLight( int light , int intensity);
void switchOnWithFade( int light , int intensity, int threshold, int time);
void switchOffLight( int light );
void disableAll();
