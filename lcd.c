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

#include "lcd.h"

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// VARIABLE DEFINITIONS

//unsigned char xdata line[4][21]; //= 20*4 +\0 *4

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

	uint8_t a =0;
	uint8_t index = 0;
	uint8_t indexPins = 0;
	uint8_t nCharsPerLine = 20;
	uint8_t writeInsideOnly = 1;
	uint8_t functionSet = (two_lines|font_5x7|bus_4bit);
	uint8_t entryMode = (writes2right_cursorMovesOnScreen);
	uint8_t cursorMode = (display_on | cursor_on | cursor_notBlinking);
	

//____________________________________________________
// other variables

unsigned char xdata addDisp _at_ 0x9000;
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
	
char putchar(char ch)
{
	LCD_printChar(0, ch);
	return ch;
}

void gpio_clear(uint8_t port, uint8_t bits)
{
	gpio_enter(port, bits, 0);
}

void gpio_enter(uint8_t port, uint8_t bits, uint8_t val)
{
	switch(port)
	{
		case(portLCD_cmd):
			switch(bits)
			{
				case(pinRS): P1_1 = val; break;
				case(pinRW): P3_4 = val; break;
				case(pinE): P3_5 = val; break;
			}
			break;	
		case(portLCD_data):
			
			break;
	}
}

void gpio_set(uint8_t port, uint8_t bits)
{
	gpio_enter(port, bits, 1);
}

void gpio_port_write(uint8_t port, uint8_t portVal)
{
	addDisp = portVal;
}

void LCD_initPredef(void)
{
}

void INIT_LCD(void)
{
	dlcd = lcds_predef;
	
	dlcd->cmd_port = portLCD_cmd;
	dlcd->data_port = portLCD_data;
	dlcd->cmdRS = pinRS;
	dlcd->cmdRW = pinRW;
	dlcd->cmdEN = pinE;

	for(a=0;a<8;a++) dlcd->data_pins[a] = a;

    //____________________________________________________
    // INIT LCD
    // initial sequence for buggy response - cheap china lcds ready flag bug fix
    LCD_writeCmd(dlcd,init_functionSet);
    LCD_waitBusy(sendCmd);
    LCD_writeCmd(dlcd,init_functionSet);
    LCD_waitBusy(sendData);
    LCD_writeCmd(dlcd,init_functionSet);

    // set initial params
    LCD_writeCmd(dlcd,functionSet); // written in 8bit mode
    //dev->i_functionSet = functionSet; // not able to change within LCD_setFunctionSet..

    LCD_writeCmd(dlcd,functionSet); // written in 4bit mode (if selected)
    LCD_writeCmd(dlcd,entryMode);
    LCD_writeCmd(dlcd,cursorMode);
}
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// EXTERNAL REFERENCES

