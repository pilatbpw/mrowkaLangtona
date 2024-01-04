#include "zapis_wyniku.h"
#include "wczytanie_planszy.h"
#include "obsluga_argumentow.h"
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
    
 
    obsluga_argumentow(argc, argv, &m, &n, &iteracje, &nazwa_wynikowa, &plansza_wejsciowa, &kierunek, &zapelnienie_procentowe);
	if(nazwa_wynikowa==NULL){
		plik_wynikowy=stdout;
	}else{
		char *sciezka_wynikowa=malloc(sizeof(nazwa_wynikowa)+sizeof("wyniki/"));
		sprintf(sciezka_wynikowa,"%s%s","wyniki/",nazwa_wynikowa);
		plik_wynikowy=fopen(sciezka_wynikowa,"w");
	}
	printf("Opcje m=%i n=%i iteracje=%i nazwa_wynikowa=%s kierunek=%s plansza_wejsciowa=%s zapelnienie_procentowe=%f\n", m, n, iteracje, nazwa_wynikowa, kierunek, plansza_wejsciowa, zapelnienie_procentowe);
	if(m!=0 && n!=0){
		y_mrowki=m/2;
		x_mrowki=n/2;
	}else{
		plik_wejsciowy=fopen(plansza_wejsciowa, "r");
		okreslenie_wielkosci_wczytanej_planszy(plik_wejsciowy, &m, &n);
		
		plik_wejsciowy=fopen(plansza_wejsciowa,"r");
		fprintf(stdout, "Test: m=%d n=%d\n", m, n);
	}
	char* plansza[m][n]; //Zainicjowanie planszy
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			plansza[m][n]=malloc(5);	
		}	
	}
	plansza[0][0]="abc";
	printf("test: %s\n", plansza[0][0]);
	if(plansza_wejsciowa==NULL){
		generowanie_planszy_poczatkowej(m,n,kierunek, y_mrowki, x_mrowki, zapelnienie_procentowe, plansza);
	}
	else{
		odczyt_planszy_poczatkowej(m, n, &y_mrowki, &x_mrowki, kierunek, plansza, plik_wejsciowy); //W TEJ FUNKCJI JEST BLAD
	}
	wypisanie_planszy(m,n,plansza,plik_wynikowy);
    return 0;
}
