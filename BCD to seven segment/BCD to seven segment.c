/*
 * BCD_to_seven_segment.c
 *
 * Created: 8/7/2018 9:57:20 AM
 *  Author: Mohamed Zaghlol
 */ 



#define  F_CPU 8000000UL
#include <util/delay.h>
#include "SEV-SEG.h"
int main(void)
{
	SEVEN_SEG_initallize('D');
	unsigned char counter=0;
    while(1)
    {
        for(counter=0;counter<=9;counter++)
		{
          BCD_to_sevseg_low('D',counter);
			
			_delay_ms(1000);
		}
    }
}