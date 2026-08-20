// 1) Build the Arduino Mega project and keep all build files
arduino-cli compile --fqbn arduino:avr:mega --build-path build arduino
// Builds the project and creates ELF, HEX, EEP, object files, etc.

// 2) Check that the ELF file was generated
ls -lh build/arduino.ino.elf
// Confirms that the final ELF executable exists.

// 3) See AVR assembly from the ELF file
avr-objdump -d build/arduino.ino.elf | less
// Shows AVR assembly code.
// Inside less, type /setup and press Enter to find setup().

// 4) See symbols and their addresses
avr-nm -n build/arduino.ino.elf | less
// Shows functions, variables, and their compiled addresses.

// 5) See ELF memory sections
avr-objdump -h build/arduino.ino.elf
// Shows .text, .data, .bss, and other ELF sections.

// 6) Read the real EEPROM from Arduino Mega 2560
avrdude -p atmega2560 -c wiring -P /dev/ttyACM0 -b 115200 -U eeprom:r:eeprom_dump.bin:r
// Arduino must be powered and connected by USB.
// Saves the real EEPROM into eeprom_dump.bin.

// 7) Read EEPROM address 100
od -An -t u1 -j 100 -N 1 eeprom_dump.bin
// Address 100 stores victoryCount.

// 8) Read EEPROM address 200
od -An -t u1 -j 200 -N 1 eeprom_dump.bin
// Address 200 stores failureCount.

// 9) See EEPROM bytes around addresses 100 and 200
xxd -g 1 -s 96 -l 112 eeprom_dump.bin
// Shows raw EEPROM bytes around both locations.
