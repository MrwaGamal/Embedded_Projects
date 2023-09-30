/*
 * safe.c
 *
 * Created: 9/25/2022 8:50:45 PM
 *  Author: marwa
 */ 

#define  F_CPU 8000000UL
#include <util/delay.h>
#include <avr/io.h>
#include "LCD.h"
#include "EEPROM.h"
#include "Keypad.h"
#include "safe.h"
char arr[4];
int main(void)
{   LCD_initallize();
	KeyPad_Initiallize();
	char digit=notpressed;
	char i;
	char flag=0;
	char tries=2;
	
	if(EEPROM_read(Eprom_statues_location)==first_time)
	{   LCD_send_string("set pass: ");
		for(i=0;i<4;i++)
		{
		do { // this piece of code make it stop at this line until something is written on the keypad
			digit=keyPad_reading();
		   } while (digit==notpressed);
		
		// once it receives a digit it perform the following piece of code
		LCD_send_char(digit);
		LCD_move_curser(1,11+i);
		_delay_ms(500);
		LCD_send_char('*');
		EEPROM_write(EProm_passward_location1+i, digit);
		}
		EEPROM_write(Eprom_statues_location,not_first_time);
		
	}
    while(flag==0)
    {  LCD_clear_screen();
		LCD_send_string("enter pass: ");
		for (i=0;i<4;i++)
		
		{ 
			     do {
				       arr[i]=keyPad_reading();
			         } while (arr[i]==notpressed);
				  
				LCD_send_char(arr[i]);
				_delay_ms(500);
				LCD_move_curser(1,13+i);
				LCD_send_char('*');
				_delay_ms(500);
		    }
			
		if (EEPROM_read(EProm_passward_location1)==arr[0] && EEPROM_read(EProm_passward_location2)==arr[1] && EEPROM_read(EProm_passward_location3)==arr[2] && EEPROM_read(EProm_passward_location4)==arr[3])	
			 
			 {
				 LCD_clear_screen();
				 LCD_send_string("right password");
				 LCD_move_curser(2,1);
				 LCD_send_string(" safe is opened");
				 flag=1;
			 }
			  else {
				       tries--;
					   if (tries>0)
					   {
						   LCD_clear_screen();
						   LCD_send_string("wrong password");
						   LCD_move_curser(2,1);
						   LCD_send_string(" tries left");
						   LCD_send_char(tries+48);
						   _delay_ms(1000);
						   
					   }
					   else {  
						         LCD_clear_screen();
						         LCD_send_string("wrong password");
						         LCD_move_curser(2,1);
						         LCD_send_string(" safe is closed");
						         flag=1;
					        }
					   
			       }
        
    }
	
}