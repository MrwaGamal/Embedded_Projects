/*
 * simple_math_game.c
 *
 * Created: 10/1/2022 7:45:07 AM
 *  Author: marwa
 */ 


#include <avr/io.h>
#include "Timer.h"
#include "LCD.h"
#include "Keypad.h"
#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/interrupt.h>


volatile int counter=0, flag=0;

int main(void)
{  int x;
	
    LCD_initallize();
	KeyPad_Initiallize();
	LCD_send_string("3+?=8");
	Timer_CTC_initallize();
	
	        do { 
				
				if (counter>=1000)
				{
					flag=1;
				}
		        x=keyPad_reading();
				 _delay_ms(200);
	        } while (x== notpressed && flag==0);
	        
			
		 if (x==notpressed)
			 {   
				 LCD_clear_screen();
				 LCD_send_string("time is over");
			 }
	       else if (x=='5')
			{   
				LCD_move_curser(2,1);
				LCD_send_string("right answer");
			}
			 
			else 
		    { 
			    LCD_move_curser(1,11);
			    LCD_send_char(x);
				LCD_move_curser(2,1);
				LCD_send_string("wrong answer");
		    }
				
    
}

ISR (TIMER0_COMP_vect)
{
	counter++;
}