/*
 * buttonHandler.h
 *
 *  Created on: Oct 30, 2015
 *      Author: rdmclean
 */

#ifndef BUTTONHANDLER_H_
#define BUTTONHANDLER_H_

#include "simonDisplay.h"
#include "globals.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>



// Get the simon region numbers. See the source code for the region numbering scheme.
uint8_t buttonHandler_getRegionNumber();

// Turn on the state machine. Part of the interlock.
void buttonHandler_enable();

// Turn off the state machine. Part of the interlock.
void buttonHandler_disable();

// Other state machines can call this function to see if the user has stopped touching the pad.
bool buttonHandler_releaseDetected();

// Standard tick function.
void buttonHandler_tick();

// This tests the functionality of the buttonHandler state machine.
// buttonHandler_runTest(int16_t touchCount) runs the test until
// the user has touched the screen touchCount times. It indicates
// that a button was pushed by drawing a large square while
// the button is pressed and then erasing the large square and
// redrawing the button when the user releases their touch.
void buttonHandler_runTest(int16_t touchCount);




#endif /* BUTTONHANDLER_H_ */
