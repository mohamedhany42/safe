/*
 * llcd.h
 *
 * Created: 4/14/2024 9:01:18 PM
 *  Author: hany9
 */ 


#ifndef LCD_H_
#define LCD_H_
#include "MY DIO.h"
#include "Icd_configuration.h"
#define CLR_SCREEN 0x01
#define CURSOR_ON_DISPLAN_ON 0x0e
#define RETURN_HOME 0x02
#define ENTRY_MODE 0x06
#if defined four_bits_mode
#define EN 0
#define RS 1
#define RW 2
#define FOUR_BITS 0x28
#elif defined eight_bits_mode
#define EN 0
#define RS 1
#define RW 2
#define EIGHT_BITS 0x38
#endif
void LCD_move_cousor(char row,char column);
void LCD_send_string(char *ptr);
void LCD_init(void);
void LCD_clear_screen();
void LCD_send_CMD(char cmd);
static void enable(void);
void LCD_send_char( char data);



#endif /* LCD_H_ */