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
//#include "XX.h"


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
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// EXTERNAL REFERENCES


#include "defines.h"
/*
unsigned char xdata xram[32768] _at_ 0x00;

unsigned char x,y,xmax,ymax;

void INIT_flashMob(){

x = y = 0;
xmax = 10+1;
ymax = 3+1;
}

//FCN

int RESOLVE_memory(){
	// kvuli prekryvu adresoveho prostoru vnitrni pameti a vnejsi.. musime zakazat vnitrni..
	// nastavenim XXX0001X

	// (AUX & 0b11100001) | 0x00000010
	AUXR = (AUXR & 0xE3) | 0x02;
}

void mwait(int cycles){
	int i = 1;
	for(;cycles!=0;cycles--)
		for(;i!=0;i++)
			_nop_();
}

void swait(int cycles){
	for(;cycles!=0;cycles--)
		_nop_();
}

// wait for a while
void wwait(){mwait(CYCLES_WHILE);}
void wwwait(int w){for(;w!=0;w--) mwait(CYCLES_WHILE);}



// returns 0 when test passed
// 1 otherwise
int CHECK_memory(){
	int i = 1;

	printf("- WRITING MEMORY\n");
	for(i=1; i!=B32_MAX; i++){
		if(i%2!=0)
			xram[i] = 1;
		else
			xram[i] = 0;
	}
	gotoxy(0,1);
	printf("- MEMORY WRITTEN!\n");
	printf("- READING MEMORY\n");
	for(i=1; i<B32_MAX; i++){
		if(i%2!=0)
			if(xram[i] != 1){
				return(1);
			}
		else
			if(xram[i] != 0){
				return(1);
			}
	}
	gotoxy(0,2);
	printf("- MEMORY'SBEEN READ!\n");

	return(0);
}

int CHECK_memoryEvent(){
	wwait();
	printf("MEMORY CHECK START.\n");
	wwait();

	if(CHECK_memory()==1){
		printf("FAILURE!");
		wwwait(3);
	}
	else{
		printf("PASSED!");
		wwwait(3);
	}

		clrscr();
}


void RUN_string(unsigned char str[]){
	int p = 0;
	while(str[p++]!=0) if(p>20) str[20] = 0;
	while(1){

		clrscr();
		gotoxy(x,y);
			wwait();
		printf("%20s",str);
			wwait();

		// next round
		x++;
		if(x==xmax) {
			x = 0;
			y++;
		}
		if(y==ymax)
			return;
	}
}

void FLASH_mob(){

		clrscr();
			wwait();
		printf("%s\n%s\n%s\n%s",
"MMMM MMM M  _ MMM  M",
"M    M__ M_/   M   M",
"MMM  M'  M'\\   M   '",
"M    MMM M '\\  M   M"
);
			wwwait(5);

		RUN_string("www.mutty.brb.cz");
}

void BUTTON_push(){


	int b1,b2,b3;
	int b1p,b2p,b3p; // previous
	long int ctr ,ctr_min, ctr_max;
	ctr = 0;
	ctr_min = -332767;
	ctr_max = 332768;

	b1=b2=b3 = 0;


		b1 = BT1;
		b2 = BT2;
		b3 = BT3;
		printf("%i\n",b1);
		printf("%i\n",b2);
		printf("%i\n",b3);

		if(b1 && b2) ctr = ctr_min;
		if(b3 && b2) ctr = ctr_max;

		if(b1 && !b1p) ctr = ctr-1;
		if(b2 && !b2p) ctr = 0;
		if(b3 && !b3p) ctr = ctr+1;

		if(ctr<ctr_min) ctr = ctr_min;
		if(ctr>ctr_max) ctr = ctr_max;
//		for(i=0;i<3;i++)
//			ctr = ctr + b[i]*i -1;

		printf("=%li=0x%08lX\n", ctr, ctr );

		swait(0xFFF);
		clrscr();
		b1p = b1;
		b2p = b2;
		b3p = b3;

}

*/
