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
    noInterrupts();

    lcgValue = generateSeed();
    lcgIndex = 0;
    currentDirection = 0;
    movementDetected = false;
    gameActive = true;
    gameFinished = false;
    newValue = false;
    num_correct = 0;
    num_wrong = 0;

    interrupts();

    turnOffLeds();

    Serial.println();
    Serial.println("================================");
    Serial.println("         NEW GAME STARTED");
    Serial.println("================================");

    Serial.print("New seed = ");
    Serial.println(lcgValue);

    setupTimer1();
}

void setup()
{
    SPI_Init();

    pinMode(LED0, OUTPUT);
    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);
    pinMode(LED3, OUTPUT);

    Joystick_Init();

    turnOffLeds();

    Serial.begin(115200);

    // A0 is used as an entropy source.
    pinMode(A0, INPUT);

    DAC_Init();

    // EEPROM_WriteByte(EEPROM_VICTORY_ADDR, 0);
    // EEPROM_WriteByte(EEPROM_FAILURE_ADDR, 0);

    // Read saved 8-bit counters from EEPROM.
    victoryCount = EEPROM_ReadByte(EEPROM_VICTORY_ADDR);
    failureCount = EEPROM_ReadByte(EEPROM_FAILURE_ADDR);

    Serial.println();
    Serial.println("================================");
    Serial.println("       SAVED GAME RESULTS");
    Serial.println("================================");

    Serial.print("Victories = ");
    Serial.println(victoryCount);

    SEND_FPGA(victoryCount);

    delay(1000);

    Serial.print("Failures  = ");
    Serial.println(failureCount);

    SEND_FPGA(failureCount);

    Serial.println("================================");

    startGame();
}

void loop()
{
   
   // Main game logic will be added here.
}
