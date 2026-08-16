#include <Arduino.h>

#include "leds.h"
#include "pins.h"

// Turn off all game LEDs.
void turnOffLeds(void)
{
    digitalWrite(LED0, LOW);
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
}

// Turn on all game LEDs.
void turnOnAllLeds(void)
{
    digitalWrite(LED0, HIGH);
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
}

// Display one direction using the corresponding LED.
void showDirection(uint8_t direction)
{
    turnOffLeds();

    switch (direction) {
        case 0:
            digitalWrite(LED0, HIGH);
            break;

        case 1:
            digitalWrite(LED1, HIGH);
            break;

        case 2:
            digitalWrite(LED2, HIGH);
            break;

        case 3:
            digitalWrite(LED3, HIGH);
            break;
    }
}
