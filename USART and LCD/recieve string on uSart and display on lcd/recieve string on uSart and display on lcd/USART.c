/*
 * USART.c
 *
 * Created: 2023-08-06 2:00:57 AM
 *  Author: Marwa Gamal
 */ 

#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/io.h>
#include "std_macros.h"

void UART_vInit(unsigned long Baud)
{
	unsigned short UBRR ;
	UBRR = (F_CPU/(16* Baud))-1;
	UBRRH = (unsigned char)(UBRR>> 8);
	UBRRL = ( unsigned char)(UBRR);
	SET_BIT( UCSRB,RXEN);
	SET_BIT( UCSRB,TXEN);
	UCSRC=(1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);
	 
}

void UART_vsendData(char data)
{
	while ( READ_BIT(UCSRA, UDRE) ==0 );
	UDR = data;
}

char UART_u8recieveData(void)
{
	while( READ_BIT(UCSRA,RXC)==0);
		return UDR;
	
}

void UART_vsendstring(char *ptr)
{
	while (*ptr!=0)
	{
		UART_vsendData(*ptr);
		ptr++;
		_delay_ms(100);
	}
}