// Daniel Davidek
// MPOR
// 2014_02_20
// t2L1
// MCU: AT89C51ED2
// fMCU: 11.059MHz

#include "waitin.h"

uint8_t STARTED_T0 = 0;

void INIT_T0m1()
{

/*
standartne delena dvema
PERIF CLOCK = XTAL/2
MODE1
PERIPH /6 --> citac
*/

// unsigned int _TMOD = TMOD & !BIT(4);
// set T0 mode 1 = 16bit tim/cnt
	TMOD = TMOD | BIT(0);
	TMOD = TMOD & NBIT(1);

// reset counter
	TH0 = 0;
	TL0 = 0;

// turn on timer 0
	TR0 = 1;
//	TCON = TCON | BIT(4);
	
}


// doba v nasobcich 50us
void pause(unsigned int doba)
{
	// if started for the first time - initialize timer
	if(STARTED_T0 == 0) INIT_T0m1();
//50us = 50e-6 
//1/50us = 1/50 e6 = 0.02e6 = 20kHz 
// fcpu = 11059 kHz
// n = f_T / f_CPU = 552,95 .= 553

// f_Periph = 11.059MHz/12 = 921.583_ kHz
// 1/921.5833333
	TH0 = 0;
	TL0 = 0;
	TR0 = 1;
	for(;doba>0; doba--){
		while(1)
			if( (TL0 + TH0<<4) >= 46 ) break;
		TH0 = 0;
		TL0 = 0;
	}
}

//doba v nasobcich 10ms
void pause10(unsigned int doba)
{
	for(;doba>0; doba--)
		pause(200);
}
