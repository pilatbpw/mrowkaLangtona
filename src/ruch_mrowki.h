#ifndef _RUCH_MROWKI
#define _RUCH_MROWKI

#include <stdio.h>
#include <stdlib.h>
#include "zapis_wyniku.h"

void ruch_mrowki(int iteracje, int a, int b, char* kierunek, int y_mrowki,int x_mrowki, char* plansza[a][b], char* nazwa_wynikowa);
void naprzod(int a, int b, int kolor, char* kierunek, int* y_mrowki, int* x_mrowki, char* plansza[a][b]);
void obrot(int a, int b, int kolor, char** kierunek, int y_mrowki, int x_mrowki, char* plansza[a][b]);
int kolor(int a, int b, int y_mrowki, int x_mrowki, char* plansza[a][b]);

#endif
