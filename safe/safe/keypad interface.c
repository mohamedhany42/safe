/*
 * keypad_interface.c
 *
 * Created: 4/19/2024 1:08:07 AM
 *  Author: hany9
 */ 


#include <avr/io.h>
#include "keypad interface.h"

#define keypad_port'D'
void keypad_initialize(void)
{
	DIOsetpin(keypad_port,0 , 1);
	DIOsetpin(keypad_port, 1, 1);
	DIOsetpin(keypad_port, 2, 1);
	DIOsetpin(keypad_port, 3, 1);
	DIOsetpin(keypad_port, 4, 0);
	DIOsetpin(keypad_port, 5, 0);
	DIOsetpin(keypad_port, 6, 0);
	DIOsetpin(keypad_port, 7, 0);
	DIO_connect_pullup(keypad_port,4,1);
	DIO_connect_pullup(keypad_port,5,1);
	DIO_connect_pullup(keypad_port,6,1);
	DIO_connect_pullup(keypad_port,7,1);
}
char keypad_check_press()
{
char arr[4][4]={{'1','2','3','/'},{'4','5','6','*'},{'7','8','9','-'},{'A','0','=','+'}};
char row,coloumn,x;
char return_value=NOTPRESSED;
for(row=0;row<4;row++)
{
	DIOwrite('D',0,1);
	DIOwrite('D',1,1);
	DIOwrite('D',2,1);
	DIOwrite('D',3,1);
	DIOwrite('D',row,0);
	
	for(coloumn=0;coloumn<4;coloumn++)
	{
		x=DIOread('D',(coloumn+4));
		if(x==0)
		{
			return_value=arr[row][coloumn];
			break;
		}
	}
	if(x==0)
	{
		break;
	}
}
return return_value ;
 }