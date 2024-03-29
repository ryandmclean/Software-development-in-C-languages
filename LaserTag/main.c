/*
 * main.c
 *
 *  Created on: Feb 9, 2017
 *      Author: rpn314
 */


#include "runningModes.h"
#include "filter.h"
#include "filterTest.h"
#include "supportFiles/buttons.h"
#include <assert.h>

#define BUTTONS_BTN2_MASK 0x4   // Bit mask for BTN2

// The program comes up in continuous mode.
// Hold BTN2 while the program starts to come up in shooter mode.
int main() {
    buttons_init();  // Init the buttons.
    if (buttons_read() & BUTTONS_BTN2_MASK) // Read the buttons to see if BTN2 is depressed.
        runningModes_shooter();               // Run shooter mode if BTN2 is depressed.
    else
        runningModes_continuous();            // Otherwise, go to continuous mode.
}
