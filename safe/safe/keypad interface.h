/*
 * keypad_interface.h
 *
 * Created: 4/19/2024 1:15:47 AM
 *  Author: hany9
 */ 


#ifndef KEYPAD INTERFACE_H_
#define KEYPAD INTERFACE_H_
#define NOTPRESSED 0xff
#include "MY DIO.h"
void keypad_initialize(void);
char keypad_check_press();



#endif /* KEYPAD INTERFACE_H_ */