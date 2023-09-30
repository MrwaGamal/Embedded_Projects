/*
 * LED.h
 *
 * Created: 8/18/2022 9:39:47 AM
 *  Author: marwa
 */ 


#ifndef LED_H_
#define LED_H_

void LED_initallize( char portname, char pinnumber);
void LED_on(char portname, char pinnumber);
void LED_off(char portname, char pinnumber);
void LED_toggle(char portname, char pinnumber);
unsigned char LED_read_statue(char portname, char pinnumber);



#endif /* LED_H_ */