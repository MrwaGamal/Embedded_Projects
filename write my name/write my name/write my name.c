/*
 * write_my_name.c
 *
 * Created: 9/19/2022 3:43:03 PM
 *  Author: marwa
 */ 


#define  F_CPU 8000000UL
#include <util/delay.h>
#include "LCD.h"

int main(void)
{ 
	LCD_initallize();
	LCD_send_string("Marwa Gamal");
    while(1)
    {
        //TODO:: Please write your application code 
    }
}