/*
 * ADC.c
 *
 * Created: 9/28/2022 3:06:55 AM
 *  Author: marwa
 */ 


#include <avr/io.h>
#include "std_macros.h"


void ADC_initallize(void)
{
	SET_BIT(ADMUX,REFS0);
	SET_BIT(ADMUX,REFS1);
	SET_BIT(ADCSRA,ADEN);
	SET_BIT(ADCSRA,ADPS2);
	SET_BIT(ADCSRA,ADPS1);
}

unsigned short ADC_u16read(void)
{  unsigned short ADC_value_return;
	SET_BIT(ADCSRA,ADSC);
	while(IS_BIT_CLR(ADCSRA,ADIF));//stay in your position till ADIF become 1
	SET_BIT(ADCSRA,ADIF); // clear ADIF
	ADC_value_return= ADCL;
	ADC_value_return |= (ADCH<<8);
	return ADC_value_return;
}