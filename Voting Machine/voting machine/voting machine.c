/*
 * voting_machine.c
 *
 * Created: 9/23/2022 5:43:27 AM
 *  Author: marwa
 */ 


#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "BUTTON.h"
#include "LCD.h"


int main(void)
{   unsigned char flag1,flag2,flag3,flag4=0;
	
	BUTTON_initallize('B',3);
	BUTTON_initallize('B',4);
	BUTTON_initallize('B',5);
	BUTTON_initallize('B',6);
	BUTTON_initallize('B',7);
	LCD_initallize();
	LCD_send_char('A');
	LCD_send_char('=');
	LCD_send_char('0');
	LCD_move_curser(1,12);
	LCD_send_char('B');
	LCD_send_char('=');
	LCD_send_char('0');
	LCD_move_curser(2,1);
	LCD_send_char('C');
	LCD_send_char('=');
	LCD_send_char('0');
	LCD_move_curser(2,12);
	LCD_send_char('D');
	LCD_send_char('=');
	LCD_send_char('0');
	

    while(1)
    {   
		if (BUTTON_read('B',3)==1)
		 {
			 flag1++;
			 LCD_move_curser(1,3);
			 LCD_send_char(flag1+48);

		 }
		
		else if (BUTTON_read('B',4)==1)
		{
			flag2++;
			LCD_move_curser(1,14);
			LCD_send_char(flag2+48); // ascii code of number from 0 to 9 is number + 48, that's why this is only available for numvers from  0 to 9

		} 
        
		else if (BUTTON_read('B',5)==1)
		{
			flag3++;
			LCD_move_curser(2,3);
			LCD_send_char(flag3+48);

		}
		
		else if (BUTTON_read('B',6)==1)
		{
			flag4++;
			LCD_move_curser(2,14);
			LCD_send_char(flag4+48);

		}
		
		else if (BUTTON_read('B',7)==1)
		{
			flag1=flag2=flag3=flag4=0;
			LCD_move_curser(1,3);
			LCD_send_char('0');
			LCD_move_curser(1,14);
			LCD_send_char('0');
			LCD_move_curser(2,3);
			LCD_send_char('0');
			LCD_move_curser(2,14);
			LCD_send_char('0');
			

		}
		_delay_ms(600);
    }
}