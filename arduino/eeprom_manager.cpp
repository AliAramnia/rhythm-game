#include <avr/io.h>

#include "eeprom_manager.h"

// Write one byte directly using the AVR EEPROM registers.
void EEPROM_WriteByte(uint16_t address, uint8_t data)
{
    while (EECR & (1 << EEPE));

    EEAR = address;
    EEDR = data;

    EECR |= (1 << EEMPE);
    EECR |= (1 << EEPE);
}

// Read one byte directly using the AVR EEPROM registers.
uint8_t EEPROM_ReadByte(uint16_t address)
{
    while (EECR & (1 << EEPE));

    EEAR = address;
    EECR |= (1 << EERE);

    return EEDR;
}
