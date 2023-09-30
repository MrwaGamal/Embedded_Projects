/*
 * EEPROM.c
 *
 * Created: 9/4/2022 6:55:42 PM
 *  Author: marwa
 */ 


#include <avr/io.h>
#include "std_macros.h"
void EEPROM_write (unsigned short address, unsigned char data)
{
	EEARL = (char)address;
	EEARH = (char)(address>>8);
	// or i can just write EEAR=address;
	
	EEDR = data;
	
	SET_BIT(EECR,2); 
	
	// to make sure that the process of writing is still working
	while (READ_BIT(EECR,EEWE)==1);
	// after exist from while this means that our writing process finished
}

unsigned char EEPROM_read(unsigned char address)
{
	
	EEARL = (char)address;
	EEARH = (char)(address>>8);
	
	SET_BIT(EECR,EERE);
	
	return EEDR;
}
