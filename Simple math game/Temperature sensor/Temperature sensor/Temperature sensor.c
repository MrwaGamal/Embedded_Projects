/*
 * Temperature_sensor.c
 *
 * Created: 9/29/2022 4:52:32 PM
 *  Author: marwa
 */ 


#include <avr/io.h>
#include "DIO.h"
#include "ADC.h"
#include "LCD.h"
int main(void)
{   
	ADC_initallize();
	 // from notebook session 14 part 1
	LCD_initallize();
	unsigned char hundreds, tens, units;
	LCD_send_string("temp = ");
    while(1)
    {    unsigned short Temperature = 0.25 * ADC_u16read();
		
		if(Temperature<10)
		{
			LCD_move_curser(1,9);
			LCD_send_char(0x30);
			LCD_send_char((Temperature%10)+48);
			LCD_send_char(0xDF);
			LCD_send_char(0x43);
		}
		else if( Temperature<100)
		{
			LCD_move_curser(1,9);
			LCD_send_char((Temperature/10)+48);
			LCD_send_char((Temperature%10)+48);
			LCD_send_char(0XDF);
			LCD_send_char(0X43);
			
		}
		else
		{
			
		}
		 
		
      
    }
}