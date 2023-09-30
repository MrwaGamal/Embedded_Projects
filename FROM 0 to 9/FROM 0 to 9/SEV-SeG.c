/*
 * SEV_SeG.c
 *
 * Created: 8/20/2022 3:35:51 PM
 *  Author: marwa
 */ 
 #define CC
 // hat changes when i want to replace common anode with common cathode
#include "DIO.h"


void SEVEN_SEG_initallize(char portname)
{
	DIO_vset_PORT_DIR(portname, 0xFF);
}

void SEVEN_SEG_write(char portname,char value)
{  
	 unsigned char arr[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x47,0x7f,0x6f};
   
	DIO_write_port(portname,arr[value]);
}