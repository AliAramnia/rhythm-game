#ifndef DAC_H
#define DAC_H

#include <stdint.h>

// Initialize the DAC7611P interface pins.
void DAC_Init(void);

// Write a 12-bit value to the DAC7611P.
void DAC_Write(uint16_t value);

// Generate a square-wave tone through the DAC.
void Tone(uint16_t frequency, uint16_t duration_ms);

// Play the victory sound sequence.
void VictorySound(void);

// Play the failure sound sequence.
void FailureSound(void);

#endif
