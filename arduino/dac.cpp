#include <Arduino.h>

#include "dac.h"
#include "pins.h"

// Initialize the DAC7611P interface.
void DAC_Init(void)
{
    pinMode(DAC_CS, OUTPUT);
    pinMode(DAC_LD, OUTPUT);
    pinMode(DAC_CLR, OUTPUT);
    pinMode(DAC_CLK, OUTPUT);
    pinMode(DAC_SDI, OUTPUT);

    digitalWrite(DAC_CS, HIGH);
    digitalWrite(DAC_LD, HIGH);
    digitalWrite(DAC_CLR, HIGH);
    digitalWrite(DAC_CLK, LOW);
    digitalWrite(DAC_SDI, LOW);
}

// Write a 12-bit digital value to the DAC7611P.
void DAC_Write(uint16_t value)
{
    value &= 0x0FFF;

    digitalWrite(DAC_CS, LOW);

    for (int i = 11; i >= 0; i--) {
        digitalWrite(DAC_SDI, (value >> i) & 1);

        digitalWrite(DAC_CLK, HIGH);
        delayMicroseconds(1);
        digitalWrite(DAC_CLK, LOW);
        delayMicroseconds(1);
    }

    digitalWrite(DAC_CS, HIGH);

    digitalWrite(DAC_LD, LOW);
    delayMicroseconds(1);
    digitalWrite(DAC_LD, HIGH);
}

// Generate a square-wave tone using the DAC output.
void Tone(uint16_t frequency, uint16_t duration_ms)
{
    uint32_t period_us = 1000000UL / frequency;
    uint32_t half_period_us = period_us / 2;
    uint32_t start = millis();

    while (millis() - start < duration_ms) {
        DAC_Write(4095);
        delayMicroseconds(half_period_us);

        DAC_Write(0);
        delayMicroseconds(half_period_us);
    }
}

// Play the victory audio sequence.
void VictorySound(void)
{
    Tone(523, 120);
    Tone(659, 120);
    Tone(784, 120);
    Tone(1047, 250);
}

// Play the failure audio sequence.
void FailureSound(void)
{
    Tone(400, 180);
    Tone(300, 180);
    Tone(200, 300);
}
