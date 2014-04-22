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

#ifndef _WAITIN_H_
#define _WAITIN_H_

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// INCLUDES
//_________> system includes
//_________> project includes
//_________> local includes
//_________> forward includes

#include "defines.h"

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// MACRO DEFINITIONS
//____________________________________________________
//constants (user-defined)
//____________________________________________________
//constants (do not change)
//____________________________________________________
// macro functions (do not use often!)
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// TYPE DEFINITIONS
//____________________________________________________
// enumerations
//____________________________________________________
// structs
//____________________________________________________
// unions

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// EXTERNAL VARIABLE DECLARATIONS
extern volatile uint32_t tic_toc_start;

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
/****************
 \brief
 \param
 \retval
 ****************/
void INIT_clk(void);

/****************
 \brief
 \param
 \retval
 ****************/
void mswait(uint32_t delay);

/****************
 \brief Stores systick stamp to global variable (MATLAB alike)
 \retval also returns the stamp
 ****************/
uint32_t _tic(void);

/****************
 \brief Count ticks of systick from the last call of _tic
 \retval interval between _tic and _toc in systick units
 ****************/
uint32_t _toc(void);

/****************
 \brief Count ticks of systick from the start time stamp
 \param start time stamp
 \retval interval between start time stamp and _tocFrom in systick units
 ****************/
uint32_t _tocFrom(uint32_t start);





void wwwait(int w);
void mwait(int cycles);

void twait(uint16_t times);
void swait(int cycles);

void INIT_T0m1();
void pause(unsigned int doba);
void pause10(unsigned int doba);

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// EXTERNAL REFERENCES

#endif
