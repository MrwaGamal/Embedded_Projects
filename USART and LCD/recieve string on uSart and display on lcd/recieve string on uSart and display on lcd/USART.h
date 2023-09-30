/*
 * IncFile1.h
 *
 * Created: 2023-08-06 2:32:09 AM
 *  Author: Marwa Gamal
 */ 


#ifndef INCFILE1_H_
#define INCFILE1_H_

void UART_vInit(unsigned long Baud);
void UART_vsendData(char data);
char UART_u8recieveData(void);

void UART_vsendstring(char *ptr);


#endif /* INCFILE1_H_ */