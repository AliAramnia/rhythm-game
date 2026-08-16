#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <stdint.h>

// LCG state shared between the game logic and Timer1 ISR.
extern volatile uint32_t lcgValue;
extern volatile uint32_t lcgIndex;
extern volatile bool newValue;

// Current game input state.
extern volatile uint8_t currentDirection;
extern volatile bool movementDetected;
extern volatile bool gameActive;
extern volatile bool gameFinished;

// Current round counters.
extern volatile uint8_t num_correct;
extern volatile uint8_t num_wrong;

// Persistent game result counters.
extern uint8_t victoryCount;
extern uint8_t failureCount;

#endif
