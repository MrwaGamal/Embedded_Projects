/*
 * recieve_string_on_uSart_and_display_on_lcd.c
 *
 * Created: 2023-08-08 6:13:31 AM
 *  Author: Marwa Gamal
 */ 

#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/io.h>
# include "USART.h"
#include "LCD.h"

int main(void)
{   LCD_initallize();
	UART_vInit(9600);
	char x;
    while(1)
    {
        x= UART_u8recieveData();
		LCD_send_char(x);
    }
}