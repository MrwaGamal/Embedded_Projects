/*
 * Keypad.h
 *
 * Created: 9/23/2022 3:09:01 AM
 *  Author: marwa
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#define portname 'D' // according to the hardware i see which port is connected to the keypad
# define notpressed 0xff
void KeyPad_Initiallize(void);
char keyPad_reading(void);

#endif /* KEYPAD_H_ */