/*
 * EEPROM.c
 *
 * Created: 4/20/2024 12:59:58 AM
 *  Author: hany9
 */ 


#include <avr/io.h>
#include "MY DIO.h"
#include "MYmacros.h"
void EEPROM_write(unsigned short address, unsigned char data )
{
	/*set up address register*/
	EEARL=(char)address;
	EEARH=(char)(address>>8);
	/*set up data register*/
	EEDR=data ;
	/*write logical one to EEMWE*/
	setbit(EECR,EEMWE);
	/*start EEPROM write by setting EEWE*/
	setbit(EECR,EEWE);
	/* wait for completion of write operation*/
	while(readbit(EECR,EEWE)==1);
}
unsigned char EEPROM_read( unsigned short address )
{
	/*set up address register*/
	EEARL=(char)address;
	EEARH=(char)(address>>8);
	/*start EEPROM read by setting EERE*/
	setbit(EECR,EERE);
	/*return data from data register*/
	return EEDR ;
}