#include "LCD.h"

void LCD_reset(void){
	
	LCD_DDRC = 0b11110000; 
	sbi(LCD_DDRD, LCD_EN);
	sbi(LCD_DDRA, LCD_RS);  
	
	cbi(LCD_PORTA, LCD_RS); 
	_delay_ms(3); 
	
	LCD_PORTC = 0b00110000;
	sbi(LCD_PORTD, LCD_EN); 
	_delay_ms(5); 
	cbi(LCD_PORTD, LCD_EN); 
	
	LCD_PORTC = 0b00110000; 
	sbi(LCD_PORTD, LCD_EN);
	_delay_us(110);
	cbi(LCD_PORTD, LCD_EN);	
	
	LCD_PORTC = 0b00110000;
	sbi(LCD_PORTD, LCD_EN);
	_delay_ms(3);
	cbi(LCD_PORTD, LCD_EN);
	
}

void LCD_start(void){
	
	LCD_PORTC = 0b00100000;
	sbi(LCD_PORTD, LCD_EN);
	_delay_ms(3);
	cbi(LCD_PORTD, LCD_EN);
	
	LCD_PORTC = 0b00100000;
	sbi(LCD_PORTD, LCD_EN);
	_delay_ms(3);
	cbi(LCD_PORTD, LCD_EN);
	
	LCD_PORTC = 0b10000000;
	sbi(LCD_PORTD, LCD_EN);
	_delay_ms(3);
	cbi(LCD_PORTD, LCD_EN);
	
	LCD_PORTC = 0b00000000;
	sbi(LCD_PORTD, LCD_EN);
	_delay_ms(3);
	cbi(LCD_PORTD, LCD_EN);

	LCD_PORTC = 0b10000000;
	sbi(LCD_PORTD, LCD_EN);
	_delay_ms(3);
	cbi(LCD_PORTD, LCD_EN);

	LCD_PORTC = 0b00000000;
	sbi(LCD_PORTD, LCD_EN);
	_delay_ms(3);
	cbi(LCD_PORTD, LCD_EN);
	
	LCD_PORTC = 0b00010000;
	sbi(LCD_PORTD, LCD_EN);
	_delay_ms(3);
	cbi(LCD_PORTD, LCD_EN);
	
	LCD_PORTC = 0b00000000;
	sbi(LCD_PORTD, LCD_EN);
	_delay_ms(3);
	cbi(LCD_PORTD, LCD_EN);
	
	LCD_PORTC = 0b01100000;	
	sbi(LCD_PORTD, LCD_EN);
	_delay_ms(3);
	cbi(LCD_PORTD, LCD_EN);
	
	LCD_PORTC = 0b00000000;
	sbi(LCD_PORTD, LCD_EN);
	_delay_ms(3);
	cbi(LCD_PORTD, LCD_EN);
	
	LCD_PORTC = 0b11110000;
	sbi(LCD_PORTD, LCD_EN);
	_delay_ms(3);
	cbi(LCD_PORTD, LCD_EN);
}

void LCD_write (void){
	
	sbi(LCD_PORTA, LCD_RS); 
	_delay_ms(3);
}
void LCD_configure (void){
	
	cbi(LCD_PORTA, LCD_RS); 
	_delay_ms(3); 
}

void LCD_send(void){
	
	sbi(LCD_PORTD, LCD_EN);
	_delay_ms(3);
	cbi(LCD_PORTD, LCD_EN);
}

void LCD_movecursor(uint8_t data){
	
	LCD_configure(); 
	LCD_PORTC = (data); 
	LCD_send(); 
	LCD_PORTC = (data << 4); 
	LCD_send(); 
	LCD_write(); 

}

void LCD_wprowadz_tekst(char* data, int k){
			
	int i = 0;
	for(i = 0; i < k; i++){
		LCD_PORTC = data[i];
		LCD_send();
		LCD_PORTC = (data[i]) << 4;
		LCD_send();
	}
				
			
}
void LCD_clear(void){
	
	LCD_configure();
	PORTC = 0;
	LCD_send();
	PORTC |= (1<<PC4);
	LCD_send();
	LCD_write();
}

void LCD_init(void){
	
	LCD_reset();
	LCD_start();
	LCD_write();
}
