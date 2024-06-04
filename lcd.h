#pragma once

#ifndef LCD_h  
#define LCD_h

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#define LCD_PORTC PORTC
#define LCD_PORTA PORTA 
#define LCD_PORTD PORTD
#define LCD_DDRC DDR(LCD_PORTC)
#define LCD_DDRD DDR(LCD_PORTD)
#define LCD_DDRA DDR(LCD_PORTA)
#define LCD_EN PD6 
#define LCD_RS PA2

#define DDR(x) _SFR_IO8(_SFR_IO_ADDR(x)-1)
#define sbi(sfr, bit) sfr|= 1 << bit 
#define cbi(sfr, bit) sfr &= ~(uint8_t)(1 << bit)
//#define PIN(x) _SFR_IO8(_SFR_IO_ADDR(x)-2)

void LCD_reset(void); 
void LCD_start(void); 
void LCD_configure (void); 
void LCD_write (void); 
void LCD_send(void); 
void LCD_movecursor(uint8_t data);
void LCD_wprowadz_tekst(char* data, int k);  
void LCD_clear(void);
void LCD_init(void);


#endif

