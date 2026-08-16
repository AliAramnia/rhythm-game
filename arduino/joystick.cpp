#include <Arduino.h>

#include "joystick.h"
#include "pins.h"

// Initialize joystick pins as inputs.
// External pull-down resistors are used by the hardware.
void Joystick_Init(void)
{
    pinMode(JOY_LEFT, INPUT);
    pinMode(JOY_UP, INPUT);
    pinMode(JOY_RIGHT, INPUT);
    pinMode(JOY_DOWN, INPUT);
}

// Read joystick direction using the original priority order.
uint8_t Joystick_Read(void)
{
    uint8_t movement = 255;

    if (digitalRead(JOY_UP) == HIGH) {
        movement = 0;
    }
    else if (digitalRead(JOY_LEFT) == HIGH) {
        movement = 1;
    }
    else if (digitalRead(JOY_RIGHT) == HIGH) {
        movement = 2;
    }
    else if (digitalRead(JOY_DOWN) == HIGH) {
        movement = 3;
    }

    return movement;
}
