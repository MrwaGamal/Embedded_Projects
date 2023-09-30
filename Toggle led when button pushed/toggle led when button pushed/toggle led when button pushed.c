/*
 * toggle_led_when_button_pushed.c
 *
 * Created: 8/18/2022 4:04:43 PM
 *  Author: marwa
 */ 


#include <avr/io.h>
#include "LED.h"
#include "BUTTON.h"

int main(void)
{   LED_initallize('D',1);
	char flag=0;
    while(1)
    { if (BUTTON_read('D',0)==1 && flag==0)
		{LED_toggle('D',1);
		flag++;}
		else if (BUTTON_read('D',0)==0)
		flag=0;
        
    }
}