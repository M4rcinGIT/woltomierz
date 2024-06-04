#ifndef ADC_h
#define ADC_h 

#include <avr/io.h>
#include <stdio.h>

void ADC_init(void);
void readADC(char *buffer, int decimalPlaces);


#endif // ADC_h