/*
 * LED.c
 *
 * Created: 8/18/2022 9:19:39 AM
 *  Author: marwa
 */ 


#include <avr/io.h>
#include "DIO.h"

void LED_initallize( char portname, char pinnumber)
{
	DIO_VsetPINDIR(portname,pinnumber,1); // 
}

void LED_on(char portname, char pinnumber)
{
	DIO_vwrite(portname, pinnumber,1);
}

void LED_off(char portname, char pinnumber)
{
	DIO_vwrite(portname, pinnumber,0);
}

void LED_toggle(char portname, char pinnumber)
{
	DIO_vtoggle(portname, pinnumber);
}
unsigned char LED_read_statue(char portname, char pinnumber)
{
	return DIO_u8read(portname, pinnumber);
}
