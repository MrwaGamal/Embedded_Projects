/*
 * seven_segment_bcd.c
 *
 * Created: 8/7/2018 10:12:05 AM
 *  Author: Mohamed Zaghlol
 */ 

#include "DIO.h"
#include "std_macros.h"
void seven_seg_init(unsigned char portname)
{
	DIO_vsetPINDir(portname,0,1);
	DIO_vsetPINDir(portname,1,1);
	DIO_vsetPINDir(portname,2,1);
	DIO_vsetPINDir(portname,3,1);
}
void seven_seg_write(unsigned char portname,unsigned char value)
{
	
	write_low_nibble(portname,value);
}