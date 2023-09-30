/*
 * Keypad.c
 *
 * Created: 9/23/2022 3:04:51 AM
 *  Author: marwa
 */ 


#include "DIO.h"
#include "Keypad.h"

void KeyPad_Initiallize(void)
{
	DIO_vset_PORT_DIR(portname,0x0f); // the first four pins are input and the last four pins are output
	DIO_enablepullup(portname,4,1);
	DIO_enablepullup(portname,5,1);
	DIO_enablepullup(portname,6,1);
	DIO_enablepullup(portname,7,1);
}

char keyPad_reading(void)
{
	char index[4][4]= {{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'A','0','=','+'}};
	char col,row,x;
	char return_value= notpressed; // if not updated this will be the return value which be a dummy data 
	                               // that indicates me on main function that no button is pressed
								   
 for(row=0;row<4;row++)
 {   
	 DIO_vwrite(portname,0,1);// output on all of them at first ones
	 DIO_vwrite(portname,1,1);
	 DIO_vwrite(portname,2,1);
	 DIO_vwrite(portname,3,1);
	 DIO_vwrite(portname,row,0);// then with each iteration it will change 
	 
	 for (col=0; col<4;col++)
	 {   x= DIO_u8read(portname,col+4);
		 if (x==0)
		  {
			  return_value= index[row][col];
			  break;
		  }
	  
	 }
	 // to make it break also from the outside loop once it breaks from the small loop
	 if(x==0)
	 break;
 }
   return return_value;
}