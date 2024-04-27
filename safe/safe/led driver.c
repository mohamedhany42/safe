/*
 * led_driver.c
 *
 * Created: 9/27/2023 5:17:25 AM
 *  Author: hany9
 */ 
#include "MY DIO.h"
void initialize_led(unsigned char portname , unsigned char pin_no)// this function to make a pin in the port as an output pin
  { 
	  DIOsetpin( portname ,  pin_no , 1);
  }
 void turn_on_led(unsigned char portname , unsigned char pin_no) 
 {
	  DIOwrite( portname,pin_no,1);
 }
 void turn_off_led(unsigned char portname , unsigned char pin_no)
 {
	 DIOwrite( portname,pin_no,0);
 }
 void toggle_led(unsigned char portname,unsigned char pin_no)
 {
	 DIOtoggle(portname,pin_no);
 }