/*
 * toggle_led.c
 *
 * Created: 8/18/2022 10:49:40 AM
 *  Author: marwa
 */ 


#include <avr/io.h>
#include "LED.h"
#define F_CPU 8000000UL
#include <util/delay.h>

int main(void)
{   LED_initallize('D',0);
    while(1)
    {
        LED_toggle('D',0) ;
		_delay_ms(1000);
    }
}