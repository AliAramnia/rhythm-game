#include "lcg.h"

// Calculate the next pseudo-random sequence value.
uint32_t nextElementLCG(
    uint32_t previous,
    uint32_t a,
    uint32_t c,
    uint32_t n,
    uint32_t m
)
{
    return (((a * previous) + c) ^ n) % m;
}
