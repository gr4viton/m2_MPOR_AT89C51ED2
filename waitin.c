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


//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// INCLUDES
//_________> project includes
#include "waitin.h"

volatile uint32_t system_tick;
volatile uint32_t tic_toc_start;



//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// TYPE DEFINITIONS
//____________________________________________________
// enumerations
//____________________________________________________
// structs
//____________________________________________________
// unions
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// VARIABLE DEFINITIONS
//____________________________________________________
// static variables
//____________________________________________________
// other variables
uint8_t STARTED_T0 = 0;
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// EXTERNAL VARIABLE DECLARATIONS
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// STATIC FUNCTION DECLARATIONS
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// STATIC FUNCTION DEFINITIONS - doxygen description should be in HEADERFILE
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// INLINE FUNCTION DEFINITIONS - doxygen description should be in HEADERFILE
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// OTHER FUNCTION DEFINITIONS - doxygen description should be in HEADERFILE
    //____________________________________________________
    // ..


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

/*
void sys_tick_handler(void)
{   // Called when systick fires 
	system_tick++;
}*/

uint32_t _tic(void)
{
    tic_toc_start = system_tick;
    return tic_toc_start;
}

uint32_t _toc(void)
{
    return system_tick - tic_toc_start;
}

uint32_t _tocFrom(uint32_t start)
{
    return system_tick - start;
}

// sleep for delay milliseconds
void mswait(uint32_t delay)
{
	uint32_t wake = system_tick + delay;
	while (wake > system_tick);
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

void twait(uint16_t times)
{
	for(;times>0; times--)
		pause(200);
}
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// EXTERNAL REFERENCES
