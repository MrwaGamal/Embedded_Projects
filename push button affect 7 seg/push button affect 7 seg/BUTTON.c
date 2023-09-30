/*
 * BUTTON.c
 *
 * Created: 8/18/2022 12:31:17 PM
 *  Author: marwa
 */ 


#include "DIO.h"

void BUTTON_initallize(char portname, char pinnumber)
{
	DIO_VsetPINDIR(portname, pinnumber, 0);
}
char BUTTON_read(char portname, char pinnumber)
{
	return DIO_u8read(portname, pinnumber);
}