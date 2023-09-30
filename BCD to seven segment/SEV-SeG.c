/*
 * SEV_SeG.c
 *
 * Created: 8/20/2022 3:35:51 PM
 *  Author: marwa
 */ 
#define CC // this is the line that changes when i want to replace common anode with common cathode
#include "DIO.h"
#include "std_macros.h"

void SEVEN_SEG_initallize(char portname)
{
	DIO_vset_PORT_DIR(portname, 0xFF);
}
void SEVEN_SEG_write(char portname,char index)
{  
	 #ifdef CC
	unsigned  char arr[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x47,0x7f,0x6f};
   #else 
    unsigned  char arr[]={~0x3f,~0x06,~0x5b,~0x4f,~0x66,~0x6d,~0x7d,~0x47,~0x7f,~0x6f};
   #endif
	DIO_write_port(portname,arr[index]);
}

void BCD_to_sevseg_low(char portname,char val)
{
	DIO_vwrite(portname,0,READ_BIT(val,0));
	DIO_vwrite(portname,1,READ_BIT(val,1));
	DIO_vwrite(portname,2,READ_BIT(val,2));
	DIO_vwrite(portname,3,READ_BIT(val,3));
}

void BCD_to_sevseg_high(char portname,char val)
{
	DIO_vwrite(portname,4,READ_BIT(val,4));
	DIO_vwrite(portname,5,READ_BIT(val,5));
	DIO_vwrite(portname,6,READ_BIT(val,6));
	DIO_vwrite(portname,7,READ_BIT(val,7));
}