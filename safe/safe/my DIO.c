/*
 * my_DIO.c
 *
 * Created: 9/27/2023 2:23:19 AM
 *  Author: Mohamed hany9
 */ 


#include <avr/io.h>
#include "MYmacros.h"

void  DIOsetpin(unsigned char portname , unsigned char pin_no , int direction )
{
	switch (portname)
	{
		case 'A':
        case 'a':
			if(direction==1) // output value the i will set the pin in this port as a output pin 
			 {
				 setbit(DDRA,pin_no); // now calling the function of setbit from the macros file i will choose the register of the port and the bit inside it 
			 }
			 else    //if the value is not output value i will clear the bit in this pin and set it as input
			 {
				clearbit(DDRA,pin_no);
			 }
			 break;
		case 'B':
		case 'b':
			if(direction==1) 
			{
				setbit(DDRB,pin_no); 
			}
			else  
			{
				clearbit(DDRB,pin_no);
			}
			break;
				
		case 'C':
		case 'c':	
				if(direction==1)
				{
					setbit(DDRC,pin_no);
				}
				else
				{
				clearbit(DDRC,pin_no);
			}
			break;
					
			case 'D':
            case 'd':
			if(direction==1)
				{
					setbit(DDRD,pin_no);
				}
				else
				{
					clearbit(DDRD,pin_no);
				}
				break;
				default:
				break;
			}
			}		
void DIOwrite(unsigned char portname,unsigned char pin_no,int outputvalue)// write the output value as high or low 
{

switch(portname)
{
	case 'A':
    case 'a':
	if(outputvalue==1)
	{
	    setbit(PORTA,pin_no);//Set the value of the given pin in the register port A as High
	}
	else
	{
		clearbit(PORTA,pin_no);//Set the value of the given pin in egister port A port A as Low
	}
	break ;
	case 'B':
    case 'b':
	if(outputvalue==1)
	{
		setbit(PORTB,pin_no);
	}
	else
	{
		clearbit(PORTB,pin_no);
	}
	break ;
	case 'C' :
    case 'c' :
	if(outputvalue==1)
	{
		setbit(PORTC,pin_no);
	}
	else
	{
		clearbit(PORTC,pin_no);
	}
	break ;
	case 'D':
    case 'd':
	
	if(outputvalue==1)
	{
		setbit(PORTD,pin_no);
	}
	else
	{
		clearbit(PORTD,pin_no);
	}
	break ;
	default:
    break ;
}
}
unsigned char DIOread(unsigned char portname , unsigned char pin_no ) //to read the value from the register pin from the port 
{
int value=0;
switch(portname)
{
 case'A':
 case'a':
 value=readbit(PINA,pin_no);
 break;

 case'B':
 case'b':
 value=readbit(PINB,pin_no);
 break;

 case'C':
 case'c':
 value=readbit(PINC,pin_no);
 break;

 case'D':
 case'd':
 value=readbit(PIND,pin_no);
 break;
 default:
 break;
}
return value ;
}

void DIOtoggle(unsigned char portname , unsigned char pin_no)
{
  switch(portname)
  {
    case'A':
    case'a':
    togglebit(PORTA,pin_no); 
    break;
    
    case'B':
    case'b':
    togglebit(PORTB,pin_no);
    break;  
      
    case'C':
    case'c':
    togglebit(PORTC,pin_no);
    break;
    
    case'D':
    case'd':
    togglebit(PORTD,pin_no);
    break;
    default:
    break;
 }
}
void DIOsetport(unsigned char portname , int direction)
{
  switch(portname)
  {
    case'A':
    case'a':
    DDRA=direction;
    break;
    
    case'B':
    case'b':
    DDRB=direction;
    break;
    
    case'C':
    case'c':
    DDRC=direction;
    break;
     
    case'D':
    case'd':
    DDRD=direction;
    break;    
}
}
void DIOtoggleport(unsigned char portname)
{
   switch(portname)
   {
     case'A':
     case'a':
     PORTA=~PORTA;
     break ;

     case'B':
     case'b':
     PORTB=~PORTB;
     break ;
  
     case'C' :
     case'c':
     PORTC=~PORTC;
     break ;

     case'D':
     case'd':
     PORTD=~PORTD;
     break ;

     default:
     break ;
}  
}
void DIOwriteport(unsigned char portname,int portvalue)
{
	switch(portname)
	{
		case 'A':
        case 'a':
		PORTA=portvalue; 
		break ;
        
		case 'B':
        case 'b':
		PORTB=portvalue; 
		break ;
      
		case 'C':
        case 'c':
		PORTC=portvalue; 
		break ;
   
		case 'D':
        case 'd':  
		PORTD=portvalue; 
		break ;
		default:
		break ;
	}
}

unsigned char DIOreadport(unsigned char portname)
{
	int value=0;
	switch(portname)
	{
		case 'A' :
		value=PINA; 
		break ;

		case 'B':
		value=PINB;
		break ;

		case 'C' :
		value=PINC;
		break ;

		case 'D':
		value=PIND; 
		break ;
		default:
		break ;
	}
	return value;
}	
	void write_low_nibble(unsigned char portname,unsigned char value)
	{
		value&=0x0f;
		switch(portname)
		{
			case 'A':
			PORTA&=0xf0;
			PORTA|=value;
			case 'B':
			PORTB&=0xf0;
			PORTB|=value;
			case 'C':
			PORTC&=0xf0;
			PORTC|=value;
			case 'D':
			PORTD&=0xf0;
			PORTD|=value;
		}
	}

	void write_high_nibble(unsigned char portname,unsigned char value)
	{
		value<<=4;
		switch(portname)
		{
			case 'A':
			PORTA&=0x0f;
			PORTA|=value;
			case 'B':
			PORTB&=0x0f;
			PORTB|=value;
			case 'C':
			PORTC&=0x0f;
			PORTC|=value;
			case 'D':
			PORTD&=0x0f;
			PORTD|=value;
		}
}
void DIO_connect_pullup(char portname ,char pinnumber, char connect_pullup)
{
	switch(portname)
	{
		case 'A':
		if(connect_pullup==1)
		{
			setbit(PORTA,pinnumber);
		}
		else
		{
			clearbit(PORTA,pinnumber);
		}
		break;
		case 'B':
		if(connect_pullup==1)
		{
			setbit(PORTB,pinnumber);
		}
		else
		{
			clearbit(PORTB,pinnumber);
		}
		break;
		case 'C':
		if(connect_pullup==1)
		{
			setbit(PORTC,pinnumber);
			
		}
		else
		{
			clearbit(PORTC,pinnumber);
		}
		break;
		case 'D':
		if(connect_pullup==1)
		{
			setbit(PORTD,pinnumber);
			
		}
		else
		{
			clearbit(PORTD,pinnumber);
		}
		break;
		
	}
}