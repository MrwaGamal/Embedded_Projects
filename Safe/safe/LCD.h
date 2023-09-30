/*
 * LCD.h
 *
 * Created: 9/15/2022 11:10:33 AM
 *  Author: marwa
 */ 


#ifndef LCD_H_
#define LCD_H_

# define portname 'A' 
# define controlport 'B'
# define EN 0
# define RS 1
# define WR 2

/* this part enables me to whenever i use any hardware i look for the port that sends the data to the LCD
   and then write the portname and also whatever port that is responsible for control pins of LCD 
   and that's more professional than sending sending it via the functions , also as for the pins 
   in the control port that is responsible for enable and register select and read/write pin id connected to mc */

#define CLR_SCREEN 0x01
#define CURSOR_ON_DISPLAN_ON 0x0e
#define RETURN_HOME 0x02
#define ENTRY_MODE 0x06
#define FOUR_BITS 0x28
#define EIGHT_BITS 0x38
// some commands for use several times in the code

void LCD_initallize();
void LCD_send_char(char data);
void LCD_send_cmd(char cmd);
void LCD_clear_screen();
void LCD_move_curser(char row, char coloumn);
void LCD_send_string(char*data);
static void ENABLE_PULSE(void); // i don't think we need this here



#endif /* LCD_H_ */