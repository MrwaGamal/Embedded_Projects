/*
 * FROM_0_to_9.c
 *
 * Created: 8/20/2022 4:22:02 PM
 *  Author: marwa
 */ 



#define F_CPU 8000000UL
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
			SEVEN_SEG_write('D',counter,'C');
			_delay_ms(1000);
		}
	}
}