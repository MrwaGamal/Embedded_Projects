/*
 * master_send_char_form_0_to_9.c
 *
 * Created: 2023-08-09 8:48:13 PM
 *  Author: Marwa Gamal
 */ 


#include <avr/io.h>
#include "SPI.h"
#define F_CPU 8000000UL
#include <util/delay.h>

int main(void)
{   SPI_MasterInit();
	unsigned char counter=0;
	
    while(counter<10)
    {
        SPI_MasterTransmitchar(counter+48);
		_delay_ms(300);
		counter++;
    }
}