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

#ifndef _KB_H_
#define _KB_H_

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// INCLUDES
//_________> system includes
//_________> project includes
//_________> local includes
//_________> forward includes
#include "defines.h"
#include "waitin.h"

#define nRows 4
#define nCols 4
#define nButtons 4

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

extern unsigned char xdata kbCW;
extern unsigned char xdata kbRow;
extern unsigned char xdata kbCol;

extern uint8_t xdata key[nRows][nCols];
extern uint8_t xdata btn[nButtons];

extern char xdata keyChar[nRows][nCols];

extern char xdata btnChar[nButtons];

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// INLINE FUNCTION DEFINITIONS
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// STATIC FUNCTION DEFINITIONS
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// OTHER FUNCTION DECLARATIONS
    //____________________________________________________
    // ..

void KB_scanPressedKeys(void);
void KB_scanPressedBtns(void);
void KB_printPressedKeys(void);
void KB_printPressedBtns(void);

void INIT_kb();


//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// EXTERNAL REFERENCES

#endif
