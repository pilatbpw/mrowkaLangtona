#include "zapis_wyniku.h"
#include "wczytanie_planszy.h"
#include "obsluga_argumentow.h"
#include "ruch_mrowki.h"
#include <string.h>

	int m = 0;  // Liczba wierszy
    int n = 0;  // Liczba kolumn
    int iteracje = 0;  // Liczba iteracji
    char *nazwa_wynikowa = NULL;  // Nazwa plików wynikowych
	char *plansza_wejsciowa = NULL; //Nazwa pliku wejsciowego
    char *kierunek = NULL;  // Kierunek początkowy mrowki g - gora d -dol p - prawo l - lewo
	double zapelnienie_procentowe =0.0; // Zapelnienie procentowe planszy czarnymi polami jesli -z zostalo podane
	FILE* plik_wynikowy; // Tam gdzie wypisywany jest plik
	FILE* plik_wejsciowy; // Plik z ktorego odczytujemy plansze jesli -w podane
	int y_mrowki=-1;
	int x_mrowki=-1;
	
int main(int argc, char *argv[]) {
    
	setlocale(LC_ALL, "C.UTF-8");
    obsluga_argumentow(argc, argv, &m, &n, &iteracje, &nazwa_wynikowa, &plansza_wejsciowa, &kierunek, &zapelnienie_procentowe);
	
	
	if(m!=0 && n!=0){
		y_mrowki=m/2;
		x_mrowki=n/2;
	}else{
		plik_wejsciowy=fopen(plansza_wejsciowa, "r");
		okreslenie_wielkosci_wczytanej_planszy(plik_wejsciowy, &m, &n);
		
		plik_wejsciowy=fopen(plansza_wejsciowa,"r");
		
	}
	char* plansza[m][n]; //Zainicjowanie planszy
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			plansza[m][n]=malloc(5);	
		}	
	}
	
	
	if(plansza_wejsciowa==NULL){
		generowanie_planszy_poczatkowej(m,n,kierunek, y_mrowki, x_mrowki, zapelnienie_procentowe, plansza);
	}
	else{
		odczyt_planszy_poczatkowej(m, n, &y_mrowki, &x_mrowki, &kierunek, plansza, plik_wejsciowy);
		
		
	}
	
	if(iteracje != 0)
	{
		
		
		if(nazwa_wynikowa!=NULL){
				fprintf(stdout, "Wyniki zapisano w katalogu /wyniki\n");
		}
		ruch_mrowki(iteracje, m, n, kierunek, y_mrowki, x_mrowki, plansza, nazwa_wynikowa);
		
	}
	

	
    return 0;
}
