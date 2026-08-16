#ifndef LEDS_H
#define LEDS_H

#include <stdint.h>

// Turn off all game LEDs.
void turnOffLeds(void);

// Turn on all game LEDs.
void turnOnAllLeds(void);

// Display the active game direction using one LED.
void showDirection(uint8_t direction);

#endif
