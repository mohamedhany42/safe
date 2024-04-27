#define  F_CPU 8000000UL
#include <util/delay.h>
#include "keypad interface.h"
#include "lcd.h"
#define  EEPROM_STATUS_LOCATION 0x20
#define  EEPROM_PASSWORD_LOCATION1 0x21
#define  EEPROM_PASSWORD_LOCATION2 0x22
#define  EEPROM_PASSWORD_LOCATION3 0x23
#define  EEPROM_PASSWORD_LOCATION4 0x24
#define MAX_TRIES 2

char arr[4];
int main(void)
{
	char value=NOTPRESSED;//oxff there is no something pressed like the keypad concept of the pullup
	char flag=0,i;
	char tries=MAX_TRIES;
	keypad_initialize();
	LCD_init();
	initialize_led('C',0);
	initialize_led('C',1);
	initialize_led('C',2);
	initialize_led('C',3);
	if (EEPROM_read(EEPROM_STATUS_LOCATION)==NOTPRESSED)//locations is ffff so it not have data in it so i can write on it
	{
		LCD_send_string("set pass:");
		for (i=0;i<=3;i++)//to enter passowrd of for numbers
		{
			do
			{
				value=keypad_check_press();
			}while (value==NOTPRESSED);
			LCD_send_char(value);
			_delay_ms(500);
			LCD_move_cousor(1,10+i);
			LCD_send_char('*');
			_delay_ms(500);
			EEPROM_write(EEPROM_PASSWORD_LOCATION1+i,value);
		}
		EEPROM_write(EEPROM_STATUS_LOCATION,0x00);// at the end of setting the password at the EEPROM i mustn make the status location 0000 to be known that it is wriiten in it
	}
	while(flag==0)//?????? ?? ????? ??? ??? ???? ???????? ?? ?? ??? ????????? ???? ????? ????? ???? ??? ??? ???? ????? ??? ???? ???????? ? ??? ?????? ??????? 
	{
		arr[0]=arr[1]=arr[2]=arr[3]=NOTPRESSED;
		LCD_clear_screen();
		LCD_send_string("check pass:");
		for (i=0;i<=3;i++)
		{
			do
			{
				arr[i]=keypad_check_press();// store what i press from the keypad in array
			}while (arr[i]==NOTPRESSED);
			LCD_send_char(arr[i]);
			_delay_ms(500);
			LCD_move_cousor(1,12+i);
			LCD_send_char('*');
			_delay_ms(500);
		}
		
		if(EEPROM_read(EEPROM_PASSWORD_LOCATION1)==arr[0] &&  EEPROM_read(EEPROM_PASSWORD_LOCATION2)==arr[1] && EEPROM_read(EEPROM_PASSWORD_LOCATION3)==arr[2] && EEPROM_read(EEPROM_PASSWORD_LOCATION4)==arr[3])
		{
			// compare the two passwords
			LCD_clear_screen();
			LCD_send_string("right password");
			LCD_move_cousor(2,1);
			LCD_send_string("safe opened");
			turn_on_led('c',2);
			turn_off_led('c',0);
			flag=1;
		}
		else
		{
			tries=tries-1;
			if (tries>0)
			{
				turn_off_led('c',2);
				LCD_clear_screen();
				LCD_send_string("wrong password");
				turn_on_led('c',0);
				_delay_ms(1000);
				LCD_clear_screen();
				LCD_send_string("tries left:");
				LCD_send_char(tries+48);
				_delay_ms(1000);
	
				
			}
			else
			{
				turn_off_led('c',2);
				turn_off_led('c',0);
				LCD_clear_screen();
				LCD_send_string("wrong password");
				LCD_move_cousor(2,1);
				LCD_send_string("safe closed");
				turn_on_led('c',1);
				turn_on_led('c',3);
				flag=1;
			}
		}
	}
}


