/**
 * @file: helloworld.h
 *
 * Copyright (c) 2009 MPOR
 *
 * @brief: This file is a header of the disp.lib library for 4x20 display
 *
 * @version $Revision: 2.0 $ $Name:  $ 
 *
 * @date: 2009-12-13
 * 
 * Compiler: uVision2 V2.20a
 */

/* moves cursor to the new position [x, y]*/
void gotoxy(unsigned char x, unsigned char y);

/* initializes display */
void disp_init(void);

/* overriden standard output*/
char putchar(char ch);

/* clears display content and moves cursor to the original position */
void clrscr(void);