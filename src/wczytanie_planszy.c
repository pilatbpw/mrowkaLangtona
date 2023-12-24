#include "wczytanie_planszy.h"

char* mrowka_L[2] = {"<", "\xe2\x97\x84"};  // [0] to czarna, [1] to biała
char* mrowka_P[2] = {">", "\xe2\x96\xba"};
char* mrowka_G[2] = {"^", "\xe2\x96\xb2"};  //Przydaloby sie pozamieniac czarne znaki mrowki na trojkaty
char* mrowka_D[2] = {"v", "\xe2\x96\xbc"};  // ale nie dzialaja znaki trojatow niewypelnionych :(
char* bialy_blok="\xe2\x96\x88";
char* czarny_blok=" ";

void generowanie_planszy_poczatkowej(int r, int c, char* kierunek, int y_mrowki,int x_mrowki, double zapelnienie_procentowe, char* plansza[r][c]) {

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


void okreslenie_wielkosci_wczytanej_planszy(FILE* plik_wejsciowy, int *r, int* c){
		int liczba_kontrolna=0;
		int aktualna_liczba_kolumn=0;
		char znak;
		while((znak=fgetc(plik_wejsciowy))!=EOF){
			if(znak=='\n'){
				aktualna_liczba_kolumn-=liczba_kontrolna*2/3;
				liczba_kontrolna=0;
				if (*r==0){
					*c=aktualna_liczba_kolumn;
				
				} else if(aktualna_liczba_kolumn!=*c){
					fprintf(stderr, "BLAD: Nieprawidlowy format pliku wejsciowego (plik wejsciowy nie jest prostokatem)\n");
					fclose(plik_wejsciowy);
					exit(1);
				}
				(*r)+=1;
				aktualna_liczba_kolumn=0;
				
			}
			else{
				if(znak!=' '){
					liczba_kontrolna+=1;
				}
				aktualna_liczba_kolumn++;
				
			}
			
		}
		
		
		fprintf(stdout, "Test: m=%d n=%d\n", *r, *c);
		fclose(plik_wejsciowy);
}

void odczyt_planszy_poczatkowej(int r, int c, int* y_mrowki, int* x_mrowki, char* kierunek, char* plansza[r][c], FILE* plik_wejsciowy){
	char znak;
	
	char seria_znakow[4]="";
	
	int y=0;
	int x=0;
	printf("test: %s\n", plansza[0][0]);
		while((znak=fgetc(plik_wejsciowy))!=EOF){
			printf("znak=%c\n",znak);
			if(znak!='\n'){
				if(znak==' ' || znak == '<' || znak=='>' || znak == '^' || znak=='v' ){
					
					plansza[y][x][0]=znak;
					
				}
				else{
					
					seria_znakow[0]=znak;
					seria_znakow[1]=fgetc(plik_wejsciowy);
					seria_znakow[2]=fgetc(plik_wejsciowy);
					seria_znakow[3]='\0';
					printf("TEST\n");
					strcpy(plansza[y][x],seria_znakow); // W TEJ LINNI WYSKAKUJE SEGMENTATION FAULT. JEST TO SPOWODOWANE TYM ZE ZLE SA PRZYPISYWANE DANE DO plansza[y][x]. TEN SAM BLAD MOZE POTEM WYSKOCZYC W generuj_poczatkowa BO TAM NIECHCACY ZROBILEM PODPINAJAC POD ADRESY. Moze tu tez tak zrobic i bedzie rozwiazane?
					printf("TEST\n");
				}
				
				if(znak!=czarny_blok[0] && strcmp(seria_znakow,bialy_blok)!=0 && znak != '<' && strcmp(seria_znakow,mrowka_L[1])!=0 && znak != '>' && strcmp(seria_znakow,mrowka_P[1])!=0 && znak != '^' && strcmp(seria_znakow,mrowka_G[1])!=0 && znak != 'v' && strcmp(seria_znakow,mrowka_D[1])!=0){
					fprintf(stderr, "BLAD: Nieznany znak w planszy wejsciowej\n");
					exit(1);
				}
				printf("plansza[%d][%d] = %s\n", y,x,plansza[y][x]);
				if(znak!=' '){
				if(znak == '<' || strcmp(seria_znakow,mrowka_L[1])==0){
					if(kierunek==NULL){
						*y_mrowki=y;
						*x_mrowki=x;
						kierunek[0]='l';
					}else{
						fprintf(stderr, "BLAD: Wiecej niz jedna mrowka na planszy wejsciowej\n");
						exit(1);
					}
				}else if(znak == '>' || strcmp(seria_znakow,mrowka_P[1])==0){
					if(kierunek==NULL){
						*y_mrowki=y;
						*x_mrowki=x;
						kierunek[0]='p';
					}else{
						fprintf(stderr, "BLAD: Wiecej niz jedna mrowka na planszy wejsciowej\n");
						exit(1);
					}
				}else if(znak == '^' || strcmp(seria_znakow,mrowka_G[1])==0){
					if(kierunek==NULL){
						*y_mrowki=y;
						*x_mrowki=x;
						kierunek[0]='g';
					}else{
						fprintf(stderr, "BLAD: Wiecej niz jedna mrowka na planszy wejsciowej\n");
						exit(1);
					}
				}else if(znak == 'v' || strcmp(seria_znakow,mrowka_D[1])==0){
					if(kierunek==NULL){
						*y_mrowki=y;
						*x_mrowki=x;
						kierunek[0]='d';
					}else{
						fprintf(stderr, "BLAD: Wiecej niz jedna mrowka na planszy wejsciowej\n");
						exit(1);
					}
				}
				}
				x++;
			}
			else{
				y++;
				x=0;
			}
			
		}
	
}

