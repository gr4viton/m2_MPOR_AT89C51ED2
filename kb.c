// Daniel Davidek
// MPOR
// 2014_02_20
// t2L1
// MCU: AT89C51ED2
// fMCU: 11.059MHz

#include "kb.h"
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// VARIABLE DEFINITIONS

unsigned char xdata kbCW _at_ 0x8003;
unsigned char xdata kbRow _at_ 0x8002;
unsigned char xdata kbCol _at_ 0x8000;

uint8_t xdata key[nRows][nCols];
uint8_t xdata btn[nButtons];

char xdata keyChar[nRows][nCols] = 
{
	{'1','2','3','A' },
	{'4','5','6','B' },
	{'7','8','9','C' },
	{'*','0','#','D' }
};

char xdata btnChar[nButtons] = {'y','b','r','g' };


//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// FUNCTION DEFINITIONS

void INIT_kb()
{
/*
	CW  0x8003
	radek 0x8002  - tlacitka + ledky
	sloupec 0x8000 
	0x90 do CW
	*/
	kbCW = 0x90; // naknfigurovat na PORT A abych k tomu mohl pristupovat
	
}



void KB_scanPressedKeys(void)
{
	uint8_t r=0;
	uint8_t c=0;
	// detect matrix keyboard keys
	for(r=0; r<nRows; r++)
	{
		kbRow = ~(1<<r);
		pause10(1); // wait for the bus to stabilize
		for(c=0;c<nRows;c++)
		{
			if(~kbCol & (1<<c))
			{
				key[r][c] = 1;	
			}
			else
				key[r][c] = 0;
		}
	}
}

void KB_scanPressedBtns(void)
{
	uint8_t r=0;
	// detect 4 buttons on the left
	for(r=0; r<nButtons; r++)
	{
		kbRow = ~(1<<(r+4));
		pause10(1); // wait for the bus to stabilize
		if(~kbCol & (1<<(r+4)))
		{
			btn[r] = 1;	
		}
		else
			btn[r] = 0;
		}
}


void KB_printPressedKeys(void)
{
	uint8_t r=0;
	uint8_t c=0;
	// print keyboard character 
	for(r=0; r<nRows; r++)
		for(c=0;c<nRows;c++)
			if(key[r][c])
				printf("%c", keyChar[r][c]);  	
}

void KB_printPressedBtns(void)
{
	uint8_t r=0;
	// print button character
	for(r=0; r<nButtons; r++)
		if(btn[r])
			printf("%c", btnChar[r]);
}

