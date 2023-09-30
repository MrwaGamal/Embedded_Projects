/*
 * LCD_driver.c
 *
 * Created: 9/15/2022 10:48:39 AM
 *  Author: marwa
 */ 

# include "DIO.h"
# include "LCD.h"
# define F_CPU 8000000UL
#include <util/delay.h>
#define eight_bit_mode

void LCD_initallize()
{
	
	_delay_ms(200);
	#if defined eight_bit_mode
	DIO_vset_PORT_DIR(portname,1);
	DIO_VsetPINDIR(controlport,RS,1);
	DIO_VsetPINDIR(controlport,EN,1);
	DIO_VsetPINDIR(controlport,WR,1);
	_delay_ms(1);
	LCD_send_cmd(EIGHT_BITS);
	_delay_ms(1);
	LCD_send_cmd(CURSOR_ON_DISPLAN_ON);
	_delay_ms(1);
	LCD_clear_screen();
	_delay_ms(10);
	LCD_send_cmd(ENTRY_MODE);
	_delay_ms(1);	
	
	#elif defined four_bit_mode
	DIO_VsetPINDIR(portname,0,1); // those four lines and the DIO write low level 
	DIO_VsetPINDIR(portname,1,1); // will change if i connect the LCD to the most pins of mc port
	DIO_VsetPINDIR(portname,2,1);
	DIO_VsetPINDIR(portname,3,1);
	DIO_VsetPINDIR(controlport,RS,1);
	DIO_VsetPINDIR(controlport,EN,1);
	DIO_VsetPINDIR(controlport,WR,1);
	_delay_ms(1);
	LCD_send_cmd(RETURN_HOME);
	_delay_ms(10);
	LCD_send_cmd(FOUR_BITS);
	_delay_ms(1);
	CD_send_cmd(CURSOR_ON_DISPLAN_ON);
	_delay_ms(1);
	LCD_clear_screen();
	_delay_ms(10);
	LCD_send_cmd(ENTRY_MODE);
	_delay_ms(1);
	#endif
	
}

static void ENABLE_PULSE(void)
{
	DIO_vwrite(controlport,EN,1);
	_delay_ms(2);
	DIO_vwrite(controlport,EN,0);
}

void LCD_send_char(char data)
{  
	#if defined eight_bit_mode
	DIO_write_port(portname,data);
	DIO_vwrite(controlport,RS,1);
	ENABLE_PULSE();
	
	#elif defined four_bit_mode
	DIO_write_low_level(portname,data>>4);
	DIO_vwrite(controlport,RS,1);
	ENABLE_PULSE();
	DIO_write_low_level(portname,data);
	DIO_vwrite(controlport,RS,1);
	ENABLE_PULSE();
	#endif
	
}


void LCD_send_cmd(char cmd)
{
	#if defined eight_bit_mode
	DIO_write_port(portname,cmd);
	DIO_vwrite(controlport,RS,0);
	ENABLE_PULSE();
	
	#elif defined four_bit_mode
	DIO_write_low_level(portname,cmd>>4);
	DIO_vwrite(controlport,RS,0);
	ENABLE_PULSE();
	DIO_write_low_level(portname,cmd);
	DIO_vwrite(controlport,RS,0);
	ENABLE_PULSE();
	#endif
	
	_delay_ms(1); // to leave enough time for executing the cmd before sending another
}

void LCD_clear_screen()
{
	LCD_send_cmd(0x01);
	_delay_ms(10);
}

void LCD_move_curser(char row, char coloumn)
{   
	if(row<1||row>2||coloumn<1||coloumn>16)
		  LCD_send_cmd(0x80);
		  
	else if(row==1)
	      LCD_send_cmd(0x80+coloumn-1);
		  
	else if(row==2)
	      LCD_send_cmd(0xc0+coloumn-1);
		
}

void LCD_send_string(char*data)
{
	while(*data !=0)
	{
		LCD_send_char(*data);
		data++;
	}
}


