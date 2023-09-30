/*
 * EEPROM.h
 *
 * Created: 9/4/2022 7:32:59 PM
 *  Author: marwa
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_


void EEPROM_write (unsigned short address, unsigned char data);
unsigned char EEPROM_read(unsigned char address);


#endif /* EEPROM_H_ */