/*
 * MY_DIO.h
 *
 * Created: 9/27/2023 4:57:30 AM
 *  Author: Mohamed hany9
 */ 


#ifndef MY DIO_H_
#define MY DIO_H_

void  DIOsetpin(unsigned char portname , unsigned char pin_no , int direction );
void  DIOwrite(unsigned char portname,unsigned char pin_no,int outputvalue);
unsigned char DIOread(unsigned char portname , unsigned char pin_no );
void DIOtoggle  (unsigned char portname , unsigned char pin_no);
void DIOsetport(unsigned char portname , int direction);
void DIOtoggleport(unsigned char portname);
void DIOwriteport(unsigned char portname,int portvalue);
unsigned char DIOreadport(unsigned char portname);
void write_low_nibble(unsigned char portname,unsigned char value);
/*
	Function Name        : write_high_nibble
	Function Returns     : void
	Function Arguments   : unsigned char portname,unsigned char value
	Function Description : write a value to the high nibble of the port 
*/
void write_high_nibble(unsigned char portname,unsigned char value);

#endif /* MY DIO_H_ */