#ifndef ADC_H
#define ADC_H

#include <stdint.h>

// Read the analog input used as the pseudo-random seed source.
uint16_t ADC_ReadSeed(void);

#endif
