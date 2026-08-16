#ifndef ADC_H
#define ADC_H

#include <stdint.h>

// Generate a new seed from analog noise on A0 and the current microsecond count.
uint32_t generateSeed(void);

#endif
