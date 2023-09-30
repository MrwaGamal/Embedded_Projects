/*
 * SPI.c
 *
 * Created: 2023-08-09 8:09:58 PM
 *  Author: Marwa Gamal
 */ 


#include <avr/io.h>
#include "std_macros.h"
#define F_CPU 8000000UL
#include <util/delay.h>
#include "DIO.h"


void SPI_MasterInit(void)
{
	DIO_VsetPINDIR('B',4,1);
	DIO_VsetPINDIR('B',5,1);
	DIO_VsetPINDIR('B',7,1);
	
	SET_BIT(SPCR,MSTR);
	
	SET_BIT(SPCR, SPR0);
	
	SET_BIT(SPCR, SPE);
	DIO_vwrite('B',4,1);
	
}

void SPI_SlaveInit(void)
{
		DIO_VsetPINDIR('B',6,1);
		SET_BIT(SPCR, SPE);
}

unsigned char SPI_MasterTransmitchar(unsigned char data)
{    // set ss pin to 0 to make slave recive as its logic low
	DIO_vwrite('B',4,0);
	
	SPDR = data;
	while(READ_BIT(SPSR,SPIF)==0);
	return SPDR;
}

unsigned char SPI_SlaveRecievechar(unsigned char data)
{
	SPDR = data;
	while(READ_BIT(SPSR,SPIF)==0);
	return SPDR;
}

void SPI_Mastertransmitstring(unsigned char *ptr)
{
	while (*ptr !=0)
	{
		SPI_MasterTransmitchar(*ptr);
		_delay_ms(300);
		ptr++;
	}
}