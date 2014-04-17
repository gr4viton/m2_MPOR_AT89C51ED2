#ifndef _DEFINES_H_
#define _DEFINES_H_

#include <intrins.h>
#include <stdio.h>
//#include <atmelWM\89C51RD2.h>
#include <89c51rd2.H>
//#include "reg51.h"



#define INT_MAX 0xffff
#define B32_MAX 0x8000
//#define CYCLES_WHILE 0x0df
#define CYCLES_WHILE 0x001

#define GET_MBYTE(BYTE,BIT) ((BYTE) & 1<<(BIT))
#define GET_BIT(BYTE,BIT) ( !(!( GET_MBYTE(BYTE,BIT) )) )
#define BIT(b) (1LU<<(b))
#define NBIT(b) (~(1LU<<(b)))
#define SET_BIT(BYTE,b) ( (BYTE) | (BIT(b)) )
#define CLR_BIT(BYTE,b) ( (BYTE) & (NBIT(b)) )
//#define SET_BIT(BYTE,BIT) (BYTE & LU1<<BIT)


//p3b3
//p1b5
//p3b4
#define BT1 !(P3&(0x04)); 
#define BT2 !(P1&(0x10));
#define BT3 !(P3&(0x08));

#define BT(num) \
( switch (num) \
  {             \ 
    case 1:  return BT1;  \
    case 2:  return BT2;  \
    case 3:  return BT3;  \
  }              \
)



// number of bit in byte
// T2MOD
#define T2OE	1
#define DCEN	0


typedef short int 	int8_t ;
typedef int 		int16_t ;
typedef long int 	int32_t ;

typedef unsigned short int 	uint8_t ;
typedef unsigned int		uint16_t ;
typedef unsigned long int 	uint32_t ;


#endif
