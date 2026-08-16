#include <Arduino.h>
#include <SPI.h>

#include "spi_manager.h"
#include "pins.h"

// Initialize SPI communication with the FPGA.
void SPI_Init(void)
{
    pinMode(FPGA_CS, OUTPUT);
    digitalWrite(FPGA_CS, HIGH);

    SPI.begin();
    SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE0));
}

// Send one byte to the FPGA.
void SPI_SendByte(uint8_t data)
{
    digitalWrite(FPGA_CS, LOW);
    SPI.transfer(data);
    digitalWrite(FPGA_CS, HIGH);
}
