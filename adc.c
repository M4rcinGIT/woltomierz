#include "adc.h"

void FloatToString(float liczba, char *bufor, int miejscaDziesietne){
	
	// Sprawdü, czy liczba jest ujemna
	if (liczba < 0)
	{
		*bufor++ = '-';
		liczba = -liczba;
	}

	// Pobierz czÍúÊ ca≥kowitπ liczby
	int czescCalkowita = (int)liczba;

	// ZamieÒ czÍúÊ ca≥kowitπ na string za pomocπ sprintf
	sprintf(bufor, "%d", czescCalkowita);

	// PrzesuÒ wskaünik na koniec czÍúci ca≥kowitej w stringu1
	while (*bufor) bufor++;

	// Dodaj kropkÍ dziesiÍtnπ do stringu
	*bufor++ = '.';

	// Oblicz czÍúÊ u≥amkowπ liczby
	float czescUlamek = liczba - czescCalkowita;

	// ZamieÒ czÍúÊ u≥amkowπ na string z okreúlonπ precyzjπ
	for (int i = 0; i < miejscaDziesietne; i++)
	{
		czescUlamek *= 10;
		int cyfra = (int)czescUlamek;
		*bufor++ = '0' + cyfra;
		czescUlamek -= cyfra;
	}

	// ZakoÒcz string znakiem null
	*bufor = '\0';
}

void ADC_init(void){
	
	ADMUX |= (1 << MUX0); // wybÛr kana≥u
	
	ADMUX |= (1 << REFS0); // ustawienie napiÍcia odniesienia
	
	ADCSRA |= (1 << ADEN); // konfiguracja adc
	// konfiguracja prescalera
	ADCSRA |= (1 << ADPS0);
	ADCSRA |= (1 << ADPS1);
	ADCSRA |= (1 << ADPS2);
	
	ADCSRA |= (1 << ADSC); // rozpoczÍcie pomiaru
}

void readADC(char *buffer, int decimalPlaces){
	
	uint16_t adc_result;
	
	//kompilacja wyniku
	adc_result = ADCL;
	adc_result |= ADCH<<8;

	float napiecie = (float)adc_result / 1023 * 5;
	FloatToString(napiecie, buffer, decimalPlaces);
}
