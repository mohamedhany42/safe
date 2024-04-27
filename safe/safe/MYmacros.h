/*
 * macros.h
 *
 * Created: 9/27/2023 2:33:41 AM
 *  Author: Mohamed hany9
 */ 

#define REGISTER_SIZE 8

#define  setbit(reg,bit)      reg|=(1<<bit)
#define  clearbit(reg,bit)    reg&=(~(1<<bit))
#define  togglebit(reg,bit)   reg^=(1<<bit)
#define  readbit(reg,bit)     ((reg&(1<<bit))>>bit)
#define ROR(reg,num)         reg=(reg<<(REGISTER_SIZE-num))|(reg>>(num))
#define ROL(reg,num)         reg=(reg>>(REGISTER_SIZE-num))|(reg<<(num))
