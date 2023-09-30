/*
 * farah_l_3omda.c
 *
 * Created: 8/18/2022 11:03:25 AM
 *  Author: marwa
 */ 


#include "LED.h"
#define F_CPU 8000000UL
#include <util/delay.h>

int main(void)
{  LED_portinitallize('D');
    while(1)
    {   signed char i;
        for(i=0; i<=7; i++) 
		{
			LED_on('D',i);
			_delay_ms(1000);
		}
		

		
		for(i=7;i>=0;i--)
		{   
			LED_off('D',i);
			_delay_ms(1000);
			
		}
    }
}