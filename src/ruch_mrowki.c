#include "ruch_mrowki.h"
#include <string.h>


char* mrowkaL[2] = {"◁", "◄"};  
char* mrowkaP[2] = {"▷", "►"};
char* mrowkaG[2] = {"△", "▲"};  
char* mrowkaD[2] = {"▽", "▼"};  
char* bloczek[2] = {" ", "█"};

void ruch_mrowki(int iteracje, int a, int b, char* kierunek, int y_mrowki, int x_mrowki, char* plansza[a][b], char* nazwa_wynikowa)
{
	if(iteracje !=0)
	{
		for(int i = 0; i < iteracje; i++)
		{
			FILE* plik_wynikowy;
			if(nazwa_wynikowa==NULL){
				plik_wynikowy=stdout;
			}else{
				
				char *sciezka_wynikowa=malloc(sizeof(nazwa_wynikowa)+sizeof("wyniki/")+10);
				sprintf(sciezka_wynikowa,"%s%s%diteracja","wyniki/",nazwa_wynikowa,i+1);
				plik_wynikowy=fopen(sciezka_wynikowa,"w");
			
			}
			int kolor_ = kolor(a, b, y_mrowki, x_mrowki, plansza) == 0;
			
			if(kolor_ == 0)
			{
			
				obrot(a, b, kolor_, &kierunek, y_mrowki, x_mrowki, plansza);
				
				
				naprzod(a, b, kolor_, kierunek, &y_mrowki, &x_mrowki, plansza);
				
			}
			else if (kolor_ == 1)
			{
				obrot(a, b, kolor_, &kierunek, y_mrowki, x_mrowki, plansza);
			
				naprzod(a, b, kolor_, kierunek, &y_mrowki, &x_mrowki, plansza);
				
			}
			else
			{
				printf("BLAD!!!!!!");
			}
			
				wypisanie_planszy(a,b,plansza,plik_wynikowy);
				
		}
	}
}

void naprzod(int a, int b, int kolor, char* kierunek, int* y_mrowki, int* x_mrowki, char* plansza[a][b])
{
	int y = *y_mrowki;
	int x = *x_mrowki;
		switch(kierunek[0])
		{
			case 'l':
				if(x !=0)
				{
					plansza[y][x]=bloczek[kolor];		
					plansza[y][x-1]=mrowkaL[kolor];
					x--;
				}
				else
				{
					plansza[y][x]=bloczek[kolor];		
					plansza[y][b-1]=mrowkaL[kolor];
					x=b-1;
				}
				break;
			case 'p':
				if(x !=b-1)
				{
					plansza[y][x]=bloczek[kolor];
					plansza[y][x+1]=mrowkaP[kolor];
					x++;
				}
				else
				{
					plansza[y][x]=bloczek[kolor];		
					plansza[y][0]=mrowkaP[kolor];
					x=0;
				}
				break;
			case 'g':
				if(y !=0)
				{
					plansza[y][x]=bloczek[kolor];
					plansza[y-1][x]=mrowkaG[kolor];
					y--;
				}
				else
				{
					plansza[y][x]=bloczek[kolor];		
					plansza[a-1][x]=mrowkaG[kolor];
					y=a-1;
				}
				break;
			case 'd':
				if(y !=a-1)
				{
					plansza[y][x]=bloczek[kolor];
					plansza[y+1][x]=mrowkaD[kolor];
					y++;	
				}
				else
				{
					plansza[y][x]=bloczek[kolor];		
					plansza[0][x]=mrowkaD[kolor];
					y=0;
				}
				break;
		}
	*x_mrowki = x;
	*y_mrowki = y;
}

int kolor(int a, int b, int y_mrowki, int x_mrowki, char* plansza[a][b]) //kolor mrowki -> biala mrowka czarne tlo
{
	if(strcmp(plansza[y_mrowki][x_mrowki], "▷") == 0 || strcmp(plansza[y_mrowki][x_mrowki], "◁") == 0 || strcmp(plansza[y_mrowki][x_mrowki], "△") == 0 || strcmp(plansza[y_mrowki][x_mrowki], "▽") == 0)
		return 0; // biala mrowka -> czarne tlo
	else if(strcmp(plansza[y_mrowki][x_mrowki], "►") == 0 || strcmp(plansza[y_mrowki][x_mrowki], "◄") == 0 || strcmp(plansza[y_mrowki][x_mrowki], "▲") == 0 || strcmp(plansza[y_mrowki][x_mrowki], "▼") == 0)
		return 1; // czarna mrowka -> biale tlo
	else
		return 2; // blad
} // dziala

void obrot(int a, int b, int kolor, char** kierunek, int y_mrowki, int x_mrowki, char* plansza[a][b])
{
	
	
	if(kolor == 1)
	{
		
		
		
		switch((*kierunek)[0])
		{
				case 'l':
				
					plansza[y_mrowki][x_mrowki]=mrowkaD[kolor];
					
					*kierunek = "d";
					
					break;
				case 'p':
				
					plansza[y_mrowki][x_mrowki]=mrowkaG[kolor];
					
					*kierunek = "g";
					
					break;
				case 'g':
			
					plansza[y_mrowki][x_mrowki]=mrowkaL[kolor];
					
					*kierunek = "l";
					
					break;
				case 'd':
				
					plansza[y_mrowki][x_mrowki]=mrowkaP[kolor];
				
					*kierunek = "p";
					
					break;
		}
		
	}
	else if(kolor == 0)
	{
		
		switch((*kierunek)[0])
		{
				case 'l':
				
					plansza[y_mrowki][x_mrowki]=mrowkaG[kolor];
					
					*kierunek = "g";
					
					break;
					
				case 'p':
				
					plansza[y_mrowki][x_mrowki]=mrowkaD[kolor];
					
					*kierunek = "d";
					
					break;
				case 'g':
				
					plansza[y_mrowki][x_mrowki]=mrowkaP[kolor];
					
					*kierunek = "p";
					
					break;
				case 'd':
				
					plansza[y_mrowki][x_mrowki]=mrowkaL[kolor];
					
					*kierunek = "l";
					
					break;
		}
		
	}
}