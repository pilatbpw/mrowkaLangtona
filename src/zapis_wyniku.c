#include "zapis_wyniku.h"

void wypisanie_planszy(int r, int c,char* plansza[r][c], FILE* plik){
	for(int i=0;i<r+2;i++){
		if(i==0){
			fprintf(plik, "\xe2\x94\x8c");
			for(int k=0;k<c;k++){
				fprintf(plik, "\xe2\x94\x80");
			}
			fprintf(plik, "\xe2\x94\x90");
		}else if(i==r+1){
			fprintf(plik, "\xe2\x94\x94");
			for(int k=0;k<c;k++){
				fprintf(plik, "\xe2\x94\x80");
			}
			fprintf(plik, "\xe2\x94\x98");
		}else{
		fprintf(plik, "\xe2\x94\x82");
			for(int j=0;j<c;j++){
					fprintf(plik, "%s", plansza[i-1][j]);
				
			}
			fprintf(plik, "\xe2\x94\x82");
		}
		fprintf(plik, "\n");
		
	}
	
	fprintf(plik, "\n");
}