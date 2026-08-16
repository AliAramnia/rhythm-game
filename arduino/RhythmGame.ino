// Rhythm Game - Arduino Mega
// Main application file.
#include "eeprom_manager.h"
#include "lcg.h"
#include "adc.h"
#include "dac.h"
#include "spi_manager.h"
#include "timer1.h"
#include "leds.h"
#include "joystick.h"
#include "game_state.h"



// Start a new 10-attempt game round.
void startGame(void)
{
    lcgValue = generateSeed();
    lcgIndex = 0;

    num_correct = 0;
    num_wrong = 0;

    movementDetected = false;
    newValue = false;

    gameActive = true;
    gameFinished = false;

    setupTimer1();
}
void setup()
{


   // Hardware initialization will be added here.
}

void loop()
{
   
   // Main game logic will be added here.
}
