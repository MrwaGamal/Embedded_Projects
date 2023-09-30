/*
 * GccApplication6.c
 *
 * Created: 8/17/2022 4:28:12 PM
 *  Author: marwa
 */ 


#include <avr/io.h>
#include "std_macros.h"

void DIO_VsetPINDIR(char portname, char pinnumber, char dir) // (v) before set stands for that this function return VOID 
{
	switch (portname)
	{
	case 'A':
	case'a':
	  if (dir==1)
	    SET_BIT(DDRA,pinnumber); // from std_macros header file
	  else                       //Set the direction of the given pin in port A as output
	    CLR_BIT(DDRA,pinnumber); //Set the direction of the given pin in port A as input
	break;
	
	
	case 'B':
	case'b':
	   if (dir==1)
	      SET_BIT(DDRB,pinnumber); 
	   else
	      CLR_BIT(DDRB,pinnumber);
	break;
	
	case 'C':
	case'c':
	   if (dir==1)
	      SET_BIT(DDRC,pinnumber);
	   else
	      CLR_BIT(DDRC,pinnumber);
	break;
	
	case 'D':
	case'd':
	  if (dir==1)
	     SET_BIT(DDRB,pinnumber);
	  else
	     CLR_BIT(DDRB,pinnumber);
	break;
	}	
	
}

 void DIO_vwrite (char portname, char pinnumber, char val )
{
	switch (portname)
	{ case 'A':
	  case'a':
	   if (val==1)
	      SET_BIT(PORTA,pinnumber); // from std_macros header file
	   else                       
	      CLR_BIT(PORTA,pinnumber); 
	break;
	
	
	case 'B':
	case'b':
	  if (val==1)
	     SET_BIT(PORTB,pinnumber);
	  else
	     CLR_BIT(PORTB,pinnumber);
	break;
	
	case 'C':
	case'c':
	  if (val==1)
	     SET_BIT(PORTC,pinnumber);
	  else
	    CLR_BIT(PORTC,pinnumber);
	break;
	
	case 'D':
	case'd':
	   if (val==1)
	     SET_BIT(PORTD,pinnumber);
	    else
	      CLR_BIT(PORTD,pinnumber);
	break;
	
	}	
}

void DIO_vtoggle (char portname, char pinnumber)
 {
	 switch (portname)
	  { case 'a':
	   case'A':
	    TOG_BIT(PORTA, pinnumber);
		break;
		
	  case 'B':
	  case'b':
	    TOG_BIT(PORTB, pinnumber);
	    break;
	  
	  case'C':
	  case'c':
	    TOG_BIT(PORTC, pinnumber);
	    break;
		
		
	  case'D':
	  case'd':
	     TOG_BIT(PORTD, pinnumber);
	     break;
		 }
	  
	  
		
 }
 
 unsigned char DIO_u8read(char portname, char pinnumber)
 { unsigned char return_value=0;
	 
	 switch (portname)
	 {  
		 
		 case 'A':
		 case'a':
		  
		  return_value  = READ_BIT(PINA, pinnumber);
		  break;
		
		 case 'B':
		 case'b':
		 
		    return_value = READ_BIT(PINB, pinnumber);
			break;
			
		 case 'C':
		 case'c':
		    return_value= READ_BIT(PINC, pinnumber);
			break;
			
		 case 'D':
		 case'd':
		    return_value= READ_BIT(PIND, pinnumber);
			break;
		 
		 
		 
	 }
	 return return_value;
 }
 
 
 void DIO_vset_PORT_DIR(char portname,char dir)
 {    switch (portname)
     {    case 'a':
	      case'A':
	           DDRA= dir;
	       break;
	 
	       case 'B':
	       case'b':
	            DDRB= dir;
	       break;
	 
	       case'C':
	       case'c':
	            DDRC= dir;
	       break;
	 
	 
	       case'D':
	       case'd':
	            DDRD= dir;
	       break;
	 }		   
 }
 void DIO_write_port(unsigned char portname,unsigned char portvalue)
 {
	 switch(portname)
	 {
		 case 'A' :
		 PORTA=portvalue; //Write the given value to the port A
		 break ;
		 case 'B':
		 PORTB=portvalue; //Write the given value to the port B
		 break ;
		 case 'C' :
		 PORTC=portvalue; //Write the given value to the port C
		 break ;
		 case 'D':
		 PORTD=portvalue; //Write the given value to the port D
		 break ;
		 default:
		 break ;
	 }
 }

 unsigned char DIO_read_port(unsigned char portname)
 {
	 unsigned char return_val=0;
	 switch(portname)
	 {
		 case 'A' :
		 return_val=PINA; // read the value of port A
		 break ;
		 case 'B':
		 return_val=PINB; // read the value of port B
		 break ;
		 case 'C' :
		 return_val=PINC; // read the value of port C
		 break ;
		 case 'D':
		 return_val=PIND; // read the value of port D
		 break ;
		 default:
		 break ;
	 }
	 return return_val;
 }
 
 /*void DIO_TOGGLE_PORT (char portname)
   {     switch (portname)
	   {    case 'a':
		    case'A':
		       PORTA= ^ PORTA;
		    break;
		   
		   case 'B':
		   case'b':
		       PORTB= ^PORTB;
		   break;
		   
		   case'C':
		   case'c':
		      PORTC= ^PORTC;
		   break;
		   
		   
		   case'D':
		   case'd':
		      PORTD=^PORTD;
		   break;
	   }
	   
   }*/
 
 void DIO_enablepullup(char portname, char pinnumber, char enable)
 {   switch(portname)
	 {
		 case'A':
		 case'a':
		    if (enable==1)
			  SET_BIT(PORTA,pinnumber);
			else
			CLR_BIT(PORTA,pinnumber);
			
		 case'B':
		 case'b':
		 
		     if (enable==1)
		     SET_BIT(PORTB,pinnumber);
		     else
		     CLR_BIT(PORTB,pinnumber);
			 break;
		 case'C':
		 case'c':
		     if (enable==1)
		     SET_BIT(PORTC,pinnumber);
		     else
		     CLR_BIT(PORTC,pinnumber);
			 break;
		 case'D':
		 case'd':
		   if (enable==1)
		   SET_BIT(PORTD,pinnumber);
		   else
		   CLR_BIT(PORTD,pinnumber);
		   break;
	 }
	 
 }
 
 void DIO_write_low_level(char portname,char val)
 {   val &=  0x0f; // 34an admn in 7ta law l user ba3tli rqm akbr mn 9 ana hsfr l high level
	 switch(portname)
	 {
	 case 'a':
	 case'A':
	     PORTA&= 0xf0; // kda ana maked sure in l low level bits equal zero and high level value never changes;
	     PORTA|= val;
	  break;
	  
	 case 'b':
	 case'B':
	    PORTB&= 0xf0; 
	    PORTB|= val;	
	 break;
	 
	 case 'c':
	 case'C':
	     PORTD&= 0xf0;
	     PORTD|= val;
	 break;
	 
	 case 'd':
	 case'D':
	    PORTD&= 0xf0;
	    PORTD|= val;
	 break;
	 }	 
	   
 }
 
  void DIO_write_high_level(char portname,char val)
  {   val <<=4; // 34an admn in 7ta law l user ba3tli rqm akbr mn 9 ana hsfr l high level
	  switch(portname)
	  {
		  case 'a':
		  case'A':
		  PORTA&= 0x0f; // kda ana maked sure in l low level bits equal zero and high level value never changes;
		  PORTA|= val;
		  break;
		  
		  case 'b':
		  case'B':
		  PORTB&= 0x0f;
		  PORTB|= val;
		  break;
		  
		  case 'c':
		  case'C':
		  PORTD&= 0x0f;
		  PORTD|= val;
		  break;
		  
		  case 'd':
		  case'D':
		  PORTD&= 0x0f;
		  PORTD|= val;
		  break;
	  }
	  
  }