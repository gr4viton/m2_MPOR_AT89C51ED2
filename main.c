// Daniel Davidek
// MPOR
// 2014_02_20
// t2L1
// MCU: AT89C51ED2
// fMCU: 11.059MHz

#include "main.h"


unsigned char xdata LED_P1 _at_ 0xA003;
unsigned char xdata LED_P2 _at_ 0xA004;
unsigned char xdata LED_P3 _at_ 0xA005;
//led
long int had;
int smer = 1;
//FCN


void timer_IT(void) interrupt 5{
	static int DIV10 = 0;
	int i =0;
	DIV10 = (DIV10 >= 9 ? DIV10+1: 0);

	if(DIV10 ==0){
		if(had == 0x800000) {
			smer = 1;
		}
		else if(had ==0x01){
			smer = 0;
	//		had = 0x01;
		}
		if(smer==0)	had <<= 1;
		else		had >>= 1;
			/*
		LED_P1 = had ;
		LED_P2 = had ;
		LED_P3 = had ;*/
	
		
		LED_P1 = had>>0 & (0xFF);
		LED_P2 = had>>8 & (0xFF);
		LED_P3 = 0x00;
		for(i=0;i<8;i++)
			if( (had>>16) & BIT(i) )
				LED_P3 = BIT(8-i);
	
	//			SET_BIT(LED_P3, 8-i);
	}
}


void INIT_T2_clock(){

	
	//CLK = FCLK/(12*(65536 - RCAP2H/RCAP2L));
	unsigned int HH = 0xB1;//20000 impulzu - zaokrouhlene
	unsigned int LL = 0xDF;

	// T_tim = 1 / (Fclk/12) .= 1.085 [us]
	// T_wanna / T_tim = N; T_tim / T_w = 1/N
	// N = 18431 = 0x47FF
	HH = 0x47;
	LL = 0xFF;

	//
	// Timer2 perioda 20ms - a hada treba
	// 16b, Up,Dn , 
	// CLK - figure 2-17
	// 		periph/6 = clk/12
	// autoreload 
	// chci inkrementalni s automatickym prednastavenim a vyvolanim interruptu


	/*
	// T2MOD
	T2MOD = SET_BIT(T2MOD,T2OE); // Set to program P1.0/T2 as clock output.
	T2MOD = SET_BIT(T2MOD,DCEN); // Set to enable Timer 2 as up/down counter.
	
	// T2CON
	T2CON = CLR_BIT(T2CON,1); // C/T2# - Cleared for timer operation (input from internal clock system: FCLK PERIPH)
	*/
	// clock

	//	had = 0x1;
	had = 0x800000;
	
	ET2 = 0; // zakaz preruseni od timeru


	LED_P1 = had;
	LED_P2 = 0x00;
	LED_P3 = 0x00;
	TR2=0; // vypnti timeru 2
	
	EA=1;  // enable global interrupt
	
	CT2=0; // T2con^1
	TR2=1; // T2con^1


	RCAP2H=HH;
	RCAP2L=LL; 
	
	TH2 = HH;
	TL2 = LL;// nastaveni timer 2


	T2MOD=0x01; //timer 2 mod 1
	TR2=1;
	ET2=1;
	
	while(1) {}
	

}

// main
void main(void){
	int i = 0;

	disp_init();
	clrscr();

//	INIT_T0m1();
	//RESOLVE_memory();

/*
	for(i=0;i<80;i++)
		line[i] = '&';
		*/

	INIT_kb();
	while(1){
		//DBG_passed();
		//DBG_snake();
		DBG_tryKb();
	}

	//INIT_uart_m3_t1();

	//while(1){_nop_();}
}

/*
do radku pisu - postupna nula
ze sloupce ctu

bity z nibblu
sloupce = 
7654|3210 - led|klavesnice

radky
4 = tlacitka
5
6
7
- = pod tim klavesnice
0 
1
2
3
*/

void DBG_tryKb(void)
{
//	const uint8_t nRows = 5;
//	const uint8_t nCols = 5;

	uint8_t r=0;
	uint8_t c=0;
	
		clrscr();	
	while(1)
	{
		KB_scanPressedKeys();
		KB_scanPressedBtns();
		//clrscr();	
		KB_printPressedKeys();
//		KB_printPressedBtns();
	}

}

void DBG_snake(void)
{
	int i = 0;
	INIT_T2_clock();
	while(1)
	{
		i++;
	}
}
void DBG_passed(void)
{
	int i = 0;
	while(1){
		clrscr();		
		printf("UBEHLO %is",i++);
		pause10(100);
	}
}












































/*

// variable baud rate
// SM1 = 1; 
SCON = SCON | BIT(6);
// SM0 = 1;
SCON = SCON | BIT(7);

// ** interrupt flags clear
//RI = 0;
SCON = SCON & NBIT(0);
//TI = 0;
SCON = SCON & NBIT(1);

// ** transmitter last bit before STOP bit = pry je to jednicka
//SCON[3] = TB8 = 1
//Transmitter Bit 8 / Ninth bit to transmit in modes 2 and 3
//Clear to transmit a logic 0 in the 9th bit.
//Set to transmit a logic 1 in the 9th bit.
//TB8 = 1;
SCON = SCON | BIT(3);


// ** ask UART to use tim1 as for his baud rate
// Receive Clock bit for UART
// Cleared to use timer 1 overflow as receive clock for serial port in mode 1 or 3.
// RCLK = 0
T2CON = T2CON & NBIT(5);

//Transmit Clock bit for UART
// Cleared to use timer 1 overflow as transmit clock for serial port in mode 1 or 3.
// TCLK = 0
T2CON = T2CON & NBIT(4);

// ***** TIMER1


//In the most typical applications, it is configured for “timer” operation, in the auto-reload mode
//(high nibble of TMOD = 0010B).
// set T1 mode 2 = 8bit tim - autoreload TL1 from TH1 at overflow
// M01 = 0;
	TMOD = TMOD & NBIT(4);
// M11 = 0;
	TMOD = TMOD & NBIT(5);



// The Timer 1 interrupt should be disabled in this application
	//T asi je vyply..


// Figure 2-21. Timer 1 Generated Commonly Used Baud Rates\
// 9-bit UARTVariable
//SM0 = 1;
SCON = SCON  &~ NBIT(7);
//SM1 = 0;
SCON = SCON  | NBIT(6);


// 9600Bd = autoreload SMOD = 0
// autoreload t1 set to 0xFD
// for 9600Bd on 11.0592 MHz
// Fperif = Fcpu/2?
	TH1 = 0xFD;
	TL1 = 0;
//SMOD1 = 0;
PCON = PCON &~ NBIT(7);
//SMOD0 = 0;
PCON = PCON &~ NBIT(6);


// enable serial
ES = 1;
EA = 1;
// turn on timer 1
	TR1 = 1;
//	TCON = TCON | BIT(4);

// ** transmission enable 
//REN = 1;
SCON = SCON | BIT(4);

// ted by mel byt zaply UART 9600b tak jak je popsany nahore
*/
//nefunkcni
