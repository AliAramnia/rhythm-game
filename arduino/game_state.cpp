#include "game_state.h"

// LCG state.
volatile uint32_t lcgValue = 1;
volatile uint32_t lcgIndex = 0;
volatile bool newValue = false;

// Current game input state.
volatile uint8_t currentDirection = 0;
volatile bool movementDetected = false;
volatile bool gameActive = true;
volatile bool gameFinished = false;

// Current round counters.
volatile uint8_t num_correct = 0;
volatile uint8_t num_wrong = 0;

// Persistent game result counters.
uint8_t victoryCount = 0;
uint8_t failureCount = 0;
