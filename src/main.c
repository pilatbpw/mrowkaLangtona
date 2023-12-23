#include "zapis_wyniku.h"
#include "wczytanie_planszy.h"
#include "obsluga_argumentow.h"
#include <string.h>
int main(int argc, char *argv[]) {
    
    int m = 0;  // Liczba wierszy
    int n = 0;  // Liczba kolumn
    int iteracje = 0;  // Liczba iteracji
    char *nazwa_wynikowa = NULL;  // Nazwa plików wynikowych
    char *kierunek = NULL;  // Kierunek początkowy mrowki g - gora d -dol p - prawo l - lewo
	double zapelnienie_procentowe =0.0;
	FILE* plik;
	
	int y_mrowki;
	int x_mrowki;

    obsluga_argumentow(argc, argv, &m, &n, &iteracje, &nazwa_wynikowa, &kierunek, &zapelnienie_procentowe);
	if(nazwa_wynikowa==NULL){
		plik=stdout;
	}else{
		char *sciezka_wynikowa=malloc(sizeof(nazwa_wynikowa)+sizeof("wyniki/"));
		sprintf(sciezka_wynikowa,"%s%s","wyniki/",nazwa_wynikowa);
		plik=fopen(sciezka_wynikowa,"w");
	}
	printf("Opcje m=%i n=%i iteracje=%i nazwa_wynikowa=%s kierunek=%s\n", m, n, iteracje, nazwa_wynikowa, kierunek);
	char *plansza[m][n]; //Zainicjowanie planszy
	y_mrowki=m/2;
	x_mrowki=n/2;

	
	generowanie_planszy_poczatkowej(m,n,kierunek, y_mrowki, x_mrowki, zapelnienie_procentowe, plansza);
	
	
	wypisanie_planszy(m,n,plansza,plik);
    return 0;
}
