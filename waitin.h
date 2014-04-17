#ifndef _WAITIN_H_
#define _WAITIN_H_

#include "defines.h"


void wwwait(int w);
void mwait(int cycles);
void swait(int cycles);

void INIT_T0m1();
void pause(unsigned int doba);
void pause10(unsigned int doba);

#endif
