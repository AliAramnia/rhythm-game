#ifndef JOYSTICK_H
#define JOYSTICK_H

#include <stdint.h>

// Initialize joystick input pins.
void Joystick_Init(void);

// Read the first detected joystick direction.
// Returns 255 when no movement is detected.
uint8_t Joystick_Read(void);

#endif
