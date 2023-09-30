/*
 * slave_recive_0_to_9_and_display_on_lcd.c
 *
 * Created: 2023-08-09 8:56:41 PM
 *  Author: Marwa Gamal
 */ 


#include <avr/io.h>
#include "spi_driver.h"
#define F_CPU 8000000UL
#include <util/delay.h>
#include "LCD.h"

int main(void)
{   SPI_SlaveInit();
	LCD_vInit();
    unsigned char x= 0x30; // ascii code of zero
	int counter=0;
	while(counter<10)
    {   
		x= SPI_SlaveReceivechar(x);
		LCD_vSend_char(x);
        counter++;
    }
}