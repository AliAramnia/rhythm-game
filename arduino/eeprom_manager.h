#ifndef EEPROM_MANAGER_H
#define EEPROM_MANAGER_H

#include <stdint.h>

// EEPROM addresses used to store persistent game results.
#define EEPROM_VICTORY_ADDR 100
#define EEPROM_FAILURE_ADDR 200

// Write one byte to the Arduino EEPROM.
void EEPROM_WriteByte(uint16_t address, uint8_t data);

// Read one byte from the Arduino EEPROM.
uint8_t EEPROM_ReadByte(uint16_t address);

#endif
