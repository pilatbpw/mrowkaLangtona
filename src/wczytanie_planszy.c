#include "wczytanie_planszy.h"

char* mrowka_L[2] = {"<", "\xe2\x97\x84"};  // [0] to czarna, [1] to biała
char* mrowka_P[2] = {">", "\xe2\x96\xba"};
char* mrowka_G[2] = {"^", "\xe2\x96\xb2"};  //Przydaloby sie pozamieniac czarne znaki mrowki na trojkaty
char* mrowka_D[2] = {"v", "\xe2\x96\xbc"};  // ale nie dzialaja znaki trojatow niewypelnionych :(
char* bialy_blok="\xe2\x96\x88";
char* czarny_blok=" ";

void generowanie_planszy_poczatkowej(int r, int c, char* kierunek, int y_mrowki,int x_mrowki, double zapelnienie_procentowe, char* plansza[r][c]){
	
	char* znak_podstawowy;
	
	znak_podstawowy=bialy_blok;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			plansza[i][j]=znak_podstawowy;
		}
		
	}
	if(zapelnienie_procentowe>0.0){
		int liczba_czarnych_blokow=(r*c)*zapelnienie_procentowe;
		srand(time(NULL));
		int rr, rc;
		while(liczba_czarnych_blokow>0){
			rr=rand()%r;
			rc=rand()%c;
			if(plansza[rr][rc][0]!=' '){
				plansza[rr][rc]=czarny_blok;
				liczba_czarnych_blokow--;
			}
			
		}
	}
	
	
	
	int kolor;
	if(plansza[y_mrowki][x_mrowki][0]==' '){ // to znaczy ze czarne pole
		kolor=0;
	}else{ //to znaczy ze biale pole
		kolor=1;
	}
	switch(kierunek[0]){
		case 'l':
			plansza[y_mrowki][x_mrowki]=mrowka_L[kolor];
			break;
		case 'p':
			plansza[y_mrowki][x_mrowki]=mrowka_P[kolor];
			break;
		case 'g':
			plansza[y_mrowki][x_mrowki]=mrowka_G[kolor];
			break;
		case 'd':
			plansza[y_mrowki][x_mrowki]=mrowka_D[kolor];
			break;
		
	}
	
	
}