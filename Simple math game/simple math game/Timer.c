/*
 * Timer.c
 *
 * Created: 10/1/2022 7:26:23 AM
 *  Author: marwa
 */ 


#include "std_macros.h"
#include <avr/io.h>
#include <avr/interrupt.h>



void Timer_CTC_initallize(void)
{   /* select CTC mode*/
	SET_BIT(TCCR0,WGM01);
	/* load a value in OCR0 */
	OCR0=78;
	/* select timer clock */
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	/* enable interrupt*/
	sei();
	SET_BIT(TIMSK,OCIE0);
}	
	
	
	
	

