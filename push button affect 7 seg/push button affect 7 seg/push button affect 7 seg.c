/*
 * push_button_affect_7_seg.c
 *
 * Created: 8/20/2022 5:37:16 PM
 *  Author: marwa
 */ 
#define F_CPU 8000000UL
#include <util/delay.h>



#include "SEV-SEG.h"
#include "BUTTON.h"
int main(void)
{   BUTTON_initallize('A',0);
	SEVEN_SEG_initallize('D');
	char  i=0;
	
    while(1)
    {   
		
        if (BUTTON_read('A',0)==1)
		 {
		    
		  if (i<=9)
		       { 
			    SEVEN_SEG_write('D',i);
			    i++ ;
			   }
			        
		  else i=0;
			
		   }  
		   _delay_ms(250); 

}
	}