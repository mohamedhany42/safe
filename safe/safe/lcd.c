/*
 * lcd.c
 *
 * Created: 4/14/2024 5:20:01 PM
 *  Author: hany9
 */ 

#include "lcd.h"
#define F_CPU 8000000UL
#include <util/delay.h>

void LCD_send_char( char data)
{
	#if defined eight_bits_mode
	DIOwriteport('A',data);
	DIOwrite('B',RS,1);//register select 1
	enable();
	
	#elif defined four_bits_mode
	write_high_nibble('A',data>>4);
	DIOwrite('B',RS,1);
	enable();
	write_high_nibble('A',data);
	DIOwrite('B',RS,1);
	enable();
	#endif
	_delay_ms(1);
}
void LCD_send_CMD(char cmd)
{
	#if defined eight_bits_mode
	DIOwriteport('A',cmd);
	DIOwrite('B',RS,0);//register select 0
	enable();
	
	#elif defined four_bits_mode
	write_high_nibble('A',cmd>>4);
	DIOwrite('B',RS,0);
	enable();
	write_high_nibble('A',cmd);
	DIOwrite('B',RS,0);
	enable();
	#endif
	_delay_ms(1);
}
static void enable(void) 
{
	DIOwrite('B',EN,1);
	_delay_ms(2);
	DIOwrite('B',EN,0);
	_delay_ms(2);
}

void LCD_clear_screen(void)
{
	LCD_send_CMD(CLR_SCREEN);
	_delay_ms(10);
}
void LCD_init(void)
{
	_delay_ms(200);
	#if defined eight_bits_mode
    DIOsetpin('A',0,1);	
	DIOsetpin('A',1,1);	
	DIOsetpin('A',2,1);
	DIOsetpin('A',3,1);
	DIOsetpin('A',4,1);
	DIOsetpin('A',5,1);
	DIOsetpin('A',6,1);
	DIOsetpin('A',7,1);
	DIOsetpin('B',EN,1);
	DIOsetpin('B',RW,1);
	DIOsetpin('B',RS,1);
	DIOwrite('B',RW,0);
	LCD_send_CMD(EIGHT_BITS);//8-bit mode
	_delay_ms(1);
	LCD_send_CMD(CURSOR_ON_DISPLAN_ON);//display cursor on lcd
	_delay_ms(1);
	LCD_send_CMD(CLR_SCREEN);
	_delay_ms(1);
	LCD_send_CMD(ENTRY_MODE);
	_delay_ms(1);
	#elif defined four_bits_mode
	DIOsetpin('A',4,1);
	DIOsetpin('A',5,1);
	DIOsetpin('A',6,1);
	DIOsetpin('A',7,1);
	DIOsetpin('B',EN,1);
	DIOsetpin('B',RW,1);
	DIOsetpin('B',RS,1);
	DIOwrite('B',RW,0);
	LCD_send_CMD(RETURN_HOME);//8-bit mode
	_delay_ms(10);
	LCD_send_CMD(FOUR_BITS);//display cursor on lcd
	_delay_ms(1);
	LCD_send_CMD(CURSOR_ON_DISPLAN_ON);//display cursor on lcd
	_delay_ms(1);
	LCD_send_CMD(CLR_SCREEN);
	_delay_ms(1);
	LCD_send_CMD(ENTRY_MODE);
	_delay_ms(1);
	#endif
}
void LCD_send_string(char *data)
{
	
	while((*data)!='\0')
	{
		LCD_send_char(*data);
		data++;
	}
	//or by pointer with array
}
void LCD_move_cousor(char row,char column)
{
	char data;
	if(row<1 || row>2 || column<0 || column>16)
	{
		data=0x80;
	}
	else if (row==1)
	{
		data=0x80+column-1;
	}
	else if (row==2)
	{
		data=0xc0+column-1;
	}
	LCD_send_CMD(data);
	_delay_ms(1);
}
 