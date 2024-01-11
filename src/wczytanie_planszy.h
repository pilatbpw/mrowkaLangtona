#ifndef _WCZYTANIE_PLANSZY
#define _WCZYTANIE_PLANSZY

#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
void generowanie_planszy_poczatkowej(int r, int c, char* kierunek, int y_mrowki,int x_mrowki, double zapelnienie_procentowe, char* plansza[r][c]);

void okreslenie_wielkosci_wczytanej_planszy(FILE* plik_wejsciowy, int *r, int* c);

void odczyt_planszy_poczatkowej(int r, int c, int* y_mrowki, int* x_mrowki, char** kierunek, char* plansza[r][c], FILE* plik_wejsciowy);
#endif
