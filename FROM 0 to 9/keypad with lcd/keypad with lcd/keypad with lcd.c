/*
 * keypad_with_lcd.c
 *
 * Created: 9/23/2022 4:11:32 AM
 *  Author: marwa
 */ 


#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "LCD.h"
#include "Keypad.h"


int main(void)
{  KeyPad_Initiallize();
	LCD_initallize();
	char x;
    while(1)
    {
		x= keyPad_reading();
		if (x!=0xff)
		{
			LCD_send_char(x);
		}
	  _delay_ms(200);
    }
}