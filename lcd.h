#ifndef _LCD_H_
#define _LCD_H_


#include "defines.h"
#include "waitin.h"
#include "dev_LCD_HD44780.h"



void gpio_enter(uint8_t port, uint8_t bits, uint8_t val);
void gpio_clear(uint8_t port, uint8_t bits);
void gpio_set(uint8_t port, uint8_t bits);
void gpio_port_write(uint8_t port, uint8_t portVal);

void LCD_initPredef(void);
#endif
