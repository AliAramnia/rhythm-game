#ifndef LCG_H
#define LCG_H

#include <stdint.h>

// Generate the next value in the Linear Congruential Generator sequence.
uint32_t nextElementLCG(
    uint32_t previous,
    uint32_t a,
    uint32_t c,
    uint32_t n,
    uint32_t m
);

#endif
