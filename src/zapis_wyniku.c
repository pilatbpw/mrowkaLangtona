#include "zapis_wyniku.h"

void wypisanie_planszy(int r, int c,char* plansza[r][c]){
	for(int i=0;i<r+2;i++){
		if(i==0){
			fprintf(stdout, "\xe2\x94\x8c");
			for(int k=0;k<c;k++){
				fprintf(stdout, "\xe2\x94\x80");
			}
			fprintf(stdout, "\xe2\x94\x90");
		}else if(i==r+1){
			fprintf(stdout, "\xe2\x94\x94");
			for(int k=0;k<c;k++){
				fprintf(stdout, "\xe2\x94\x80");
			}
			fprintf(stdout, "\xe2\x94\x98");
		}else{
		fprintf(stdout, "\xe2\x94\x82");
			for(int j=0;j<c;j++){
					fprintf(stdout, "%s", plansza[i-1][j]);
				
			}
			fprintf(stdout, "\xe2\x94\x82");
		}
		fprintf(stdout, "\n");
		
	}
	
	
}