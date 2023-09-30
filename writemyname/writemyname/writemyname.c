/*
 * writemyname.c
 *
 * Created: 9/19/2022 4:24:46 PM
 *  Author: marwa
 */ 


#define  F_CPU 8000000UL
#include <util/delay.h>
#include "LCD.h"

int main(void)
{
	LCD_initallize();
	LCD_send_string("Marwa Gamal");
	
	LCD_send_cmd(0x40);
	LCD_send_char()
	while(1)
	{   
		//TODO:: Please write your application code
	}
}