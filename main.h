#ifndef _MAIN_H_
#define _MAIN_H_


#include <intrins.h>
#include <stdio.h>
//#include <89c51rd2.H>

#include "defines.h"

#include "disp.h"
#include "kb.h"
#include "waitin.h"


void INIT_uart_m3_t1();
int RESOLVE_memory();

void DBG_tryKb(void);
void DBG_passed(void);

void INIT_T2_clock();

#endif
