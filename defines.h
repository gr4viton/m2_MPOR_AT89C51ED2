/***********
\project    MPOR - AT89 kit
\author 	xdavid10
\filename	.h
\contacts	Bc. Daniel DAVIDEK	<danieldavidek@gmail.com>
\date		17-04-2014
\brief      Drivers and demos on kit with AT89
    MCU: AT89C51ED2
    fMCU: 11.059MHz
\license    LGPL License Terms \ref lgpl_license
***********/
/* DOCSTYLE: gr4viton_2014_A <goo.gl/1deDBa> */

#ifndef _DEFINES_H_
#define _DEFINES_H_

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// INCLUDES
//_________> system includes
//_________> project includes
//_________> local includes
//_________> forward includes

#include <intrins.h>
#include <stdio.h>
#include <89c51rd2.H>
//#include <atmelWM\89C51RD2.h>
//#include "reg51.h"


//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// MACRO DEFINITIONS
//____________________________________________________
//constants (user-defined)
//____________________________________________________
//constants (do not change)
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

#define BT1 !(P3&(1<<2)); //p3b3=1<<3-1
#define BT2 !(P1&(1<<4)); //p1b5
#define BT3 !(P3&(1<<3)); //p3b4

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
//____________________________________________________
// macro functions (do not use often!)
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// TYPE DEFINITIONS
typedef short int 	int8_t ;
typedef int 		int16_t ;
typedef long int 	int32_t ;

typedef unsigned short int 	uint8_t ;
typedef unsigned int		uint16_t ;
typedef unsigned long int 	uint32_t ;
//____________________________________________________
// enumerations
//____________________________________________________
// structs
//____________________________________________________
// unions

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// EXTERNAL VARIABLE DECLARATIONS
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// INLINE FUNCTION DEFINITIONS
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// STATIC FUNCTION DEFINITIONS
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// OTHER FUNCTION DECLARATIONS
    //____________________________________________________
    // ..
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// EXTERNAL REFERENCES



#endif
