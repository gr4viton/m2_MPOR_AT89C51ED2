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
#include "defines.h"

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
void INIT_uart_m3_t1(){
    // ***** UART
    // ** set MODE 3
    // 11b = 1START, 8data, 1 programable, 1STOP

    /*nastaveni modu3*/
    /*timer 1 mod 2*/
    TMOD = TMOD &(~BIT(4));
    TMOD = TMOD | BIT(5);

    //nastaveni poc hodnoty timeru*/
    TH1 = 0xFD;
    /*smod do 0 .. z tabulky*/
    PCON = PCON & (~BIT(7));

    SCON = SCON &(~BIT(7));
    /*nastaveni seriovky do modu 1*/
    SCON = SCON | BIT(6);
    /*enable serial reception*/
    SCON = SCON | BIT (4);

    RCLK = 0;	/*use timer 1 for transmit and receive*/
    TCLK = 0;

    ES = 1; 	/*Enable serial interrupt*/
    EA = 1;	/*Enable global interupt*/
    TR1 = 1;	/*Timer 1 run*/

}
//funkce pro obsluhu preruseni
// viz prednaska4 slide24
void serial_IT(void) interrupt 4{
    static int i =0;
    static int act_row=0;
    int k=0;
    int l =0;
    static int rolling =0;
    int j=0;

    char ch;
//	if( SCON | BIT(0) ) {
	if(RI==1){
	// recieving
		// ** interrupt flags clear
		//RI = 0;
		SCON = SCON & NBIT(0);
		gotoxy(i,act_row);
		ch = SBUF;
		i++;

		if(ch=='\n' || i>20){
			line[act_row][i+1] = '\0';
			i=0;
			act_row = act_row + 1;
			if(act_row >= 4){
			 // roll the text
				act_row = 0;
				rolling = 1;
			}
			if(rolling==1){
				//ROLLING
				// do not move lines
				// instead start to write over them
				// and in the rolling select the appropriate lines
				clrscr();
				gotoxy(0,0);

				k = act_row+1;
				if(k>=4) k=0; // only 3 lines

				for(j=3;j!=0;j--)
				{
					//printf("%s\n",line[k]);
					for(l=0;;l++){
						if(l>20) break;
						if(line[k][l]=='\0') {
							putchar('\n');
							break;
						}
						putchar(line[k][l]);
					}
					k++;
					if(k>=4) k=0;
				}
			}
		}
		else{
			line[act_row][i] = ch;
			putchar(ch);
		}

		SBUF = ch;

	}
	else TI = 0;
/*
	if( SCON | BIT(0) ) {
	// transmitting
//		SBUF
		// ** interrupt flags clear
		//TI = 0;
		SCON = SCON & NBIT(1);
		}
 */
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// EXTERNAL REFERENCES

