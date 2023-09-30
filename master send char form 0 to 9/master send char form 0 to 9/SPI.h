/*
 * IncFile1.h
 *
 * Created: 2023-08-09 8:48:41 PM
 *  Author: Marwa Gamal
 */ 


#ifndef INCFILE1_H_
#define INCFILE1_H_
void SPI_MasterInit(void);
void SPI_SlaveInit(void);
unsigned char SPI_MasterTransmitchar(unsigned char data);
unsigned char SPI_SlaveRecievechar(unsigned char data);
void SPI_Mastertransmitstring(unsigned char *ptr);



#endif /* INCFILE1_H_ */