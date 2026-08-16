#ifndef SPI_MANAGER_H
#define SPI_MANAGER_H

#include <stdint.h>

// Initialize SPI communication with the FPGA.
void SPI_Init(void);

// Send one byte to the FPGA.
void SEND_FPGA(uint8_t data);
#endif
