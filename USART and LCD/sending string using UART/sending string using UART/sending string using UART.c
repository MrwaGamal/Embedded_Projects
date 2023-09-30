/*
 * sending_string_using_UART.c
 *
 * Created: 2023-08-07 4:47:27 AM
 *  Author: Marwa Gamal
 */ 


#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "USART.h"

int main(void)
{   UART_vInit(9600);
	_delay_ms(300);
	UART_vsendstring("marwa");
    while(1)
    {
        
    }
}