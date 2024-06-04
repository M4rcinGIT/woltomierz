#include "LCD.h"
#include "ADC.h"



int main(void){
	char wynik[4]; // przechowuje wynik pomiaru po konwersji
		 
	LCD_init(); // inicjalizacja LCD
		 
	ADC_init(); // inicjalizajca ADC
	  
    while (1) 
    {
		if(bit_is_set(ADCSRA, ADIF)){
		
			readADC(wynik, 4); // wykonanie pomaru oraz konwersja
			
			// wyœwietlenie wyniku pomiaru na ekranie LCD
			LCD_wprowadz_tekst(wynik, 4);
			_delay_ms(20);
			LCD_wprowadz_tekst(" V", 2);
			_delay_ms (500);

			//powrót do stanu pocz¹tkowego wyœwietlacza
			LCD_clear();
			// zakoñczenie pomiaru
			ADCSRA |= (1 << ADSC);
	}
		
	}
}

