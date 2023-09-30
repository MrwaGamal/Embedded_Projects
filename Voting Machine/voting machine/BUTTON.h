/*
 * BUTTON.h
 *
 * Created: 8/18/2022 12:38:04 PM
 *  Author: marwa
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_


void BUTTON_initallize(char portname, char pinnumber);
char BUTTON_read(char portname, char pinnumber);

#endif /* BUTTON_H_ */