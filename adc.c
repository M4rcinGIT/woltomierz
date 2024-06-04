#include "adc.h"

void FloatToString(float liczba, char *bufor, int miejscaDziesietne){
	
	// Sprawd�, czy liczba jest ujemna
	if (liczba < 0)
	{
		*bufor++ = '-';
		liczba = -liczba;
	}

	// Pobierz cz�� ca�kowit� liczby
	int czescCalkowita = (int)liczba;

	// Zamie� cz�� ca�kowit� na string za pomoc� sprintf
	sprintf(bufor, "%d", czescCalkowita);

	// Przesu� wska�nik na koniec cz�ci ca�kowitej w stringu1
	while (*bufor) bufor++;

	// Dodaj kropk� dziesi�tn� do stringu
	*bufor++ = '.';

	// Oblicz cz�� u�amkow� liczby
	float czescUlamek = liczba - czescCalkowita;

	// Zamie� cz�� u�amkow� na string z okre�lon� precyzj�
	for (int i = 0; i < miejscaDziesietne; i++)
	{
		czescUlamek *= 10;
		int cyfra = (int)czescUlamek;
		*bufor++ = '0' + cyfra;
		czescUlamek -= cyfra;
	}

	// Zako�cz string znakiem null
	*bufor = '\0';
}

void ADC_init(void){
	
	ADMUX |= (1 << MUX0); // wyb�r kana�u
	
	ADMUX |= (1 << REFS0); // ustawienie napi�cia odniesienia
	
	ADCSRA |= (1 << ADEN); // konfiguracja adc
	// konfiguracja prescalera
	ADCSRA |= (1 << ADPS0);
	ADCSRA |= (1 << ADPS1);
	ADCSRA |= (1 << ADPS2);
	
	ADCSRA |= (1 << ADSC); // rozpocz�cie pomiaru
}

void readADC(char *buffer, int decimalPlaces){
	
	uint16_t adc_result;
	
	//kompilacja wyniku
	adc_result = ADCL;
	adc_result |= ADCH<<8;

	float napiecie = (float)adc_result / 1023 * 5;
	FloatToString(napiecie, buffer, decimalPlaces);
}
