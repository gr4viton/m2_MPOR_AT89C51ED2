#ifndef _LCD_H_
#define _LCD_H_


#include "defines.h"
#include "waitin.h"
#include "dev_LCD_HD44780.h"



void gpio_clear(uint32_t port, uint8_t bits);
void gpio_set(uint32_t port, uint8_t bits);
void gpio_port_write(uint32_t port, uint8_t bits);

void LCD_initPredef(void);
#endif
