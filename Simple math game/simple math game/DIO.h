/*
 * DIO.h
 *
 * Created: 8/17/2022 6:47:12 PM
 *  Author: marwa
 */ 


#ifndef DIO_H_
#define DIO_H_


void DIO_VsetPINDIR(char portname, char pinnumber, char dir);
void DIO_vwrite (char portname, char pinnumber, char val );
void DIO_vtoggle (char portname, char pinnumber);
unsigned char DIO_u8read(char portname, char pinnumber);
void DIO_vset_PORT_DIR(char portname,char dir);
void DIO_write_port(unsigned char portname,unsigned char portvalue);
unsigned char DIO_read_port(unsigned char portname);
void DIO_TOGGLE_PORT (char portname);
void DIO_enablepullup(char portname, char pinnumber, char enable);
void DIO_write_low_level(char portname,char val);
 void DIO_write_high_level(char portname,char val);





#endif /* DIO_H_ */