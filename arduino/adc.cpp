#include <Arduino.h>

#include "adc.h"

// Generate a seed using the analog noise present on A0.
uint32_t generateSeed(void)
{
    uint32_t seed = 0;

    seed ^= analogRead(A0);
    seed ^= ((uint32_t)analogRead(A0) << 10);
    seed ^= ((uint32_t)analogRead(A0) << 20);
    seed ^= micros();

    seed = seed * 1664525UL + 1013904223UL;

    if (seed == 0) {
        seed = 1;
    }

    return seed;
}
