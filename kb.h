#ifndef _KB_H_
#define _KB_H_


#include "defines.h"
#include "waitin.h"

#define nRows 4
#define nCols 4
#define nButtons 4

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// EXTERN variable declarations

extern unsigned char xdata kbCW;
extern unsigned char xdata kbRow;
extern unsigned char xdata kbCol;

extern uint8_t xdata key[nRows][nCols];
extern uint8_t xdata btn[nButtons];

extern char xdata keyChar[nRows][nCols];

extern char xdata btnChar[nButtons];

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// FUNCTION DECLARATIONS
void KB_scanPressedKeys(void);
void KB_scanPressedBtns(void);
void KB_printPressedKeys(void);
void KB_printPressedBtns(void);

void INIT_kb();

#endif
