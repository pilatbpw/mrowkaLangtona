#include "ruch_mrowki.h"
#include <string.h>
#include <unistd.h>

char* mrowkaL[2] = {"◁", "◄"};  
char* mrowkaP[2] = {"▷", "►"};
char* mrowkaG[2] = {"△", "▲"};  
char* mrowkaD[2] = {"▽", "▼"};  
char* bloczek[2] = {" ", "█"};

void ruch_mrowki(int iteracje, int a, int b, char* kierunek, int y_mrowki, int x_mrowki, char* plansza[a][b])
{
	if(iteracje !=0)
	{
		for(int i = 0; i < iteracje; i++)
		{
			int kolor_ = kolor(a, b, y_mrowki, x_mrowki, plansza) == 0;
			if(kolor_ == 0)
			{
				obrot(a, b, kolor_, kierunek, y_mrowki, x_mrowki, plansza);
				//printf("kierunek %s \n", kierunek);
				naprzod(a, b, kolor_, kierunek, &y_mrowki, &x_mrowki, plansza);
			}
			else if (kolor_ == 1)
			{
				obrot(a, b, kolor_, kierunek, y_mrowki, x_mrowki, plansza);
				//printf("kierunek %s \n", kierunek);
				naprzod(a, b, kolor_, kierunek, &y_mrowki, &x_mrowki, plansza);
			}
			else
			{
				printf("BLAD!!!!!!");
			}	
			//printf("%i %i %s \n", y_mrowki, x_mrowki, kierunek);
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
					plansza[y][x]=bloczek[1-kolor];		
					plansza[y][x-1]=mrowkaL[kolor];
					x--;
				}
				break;
			case 'p':
				if(x !=b)
				{
					plansza[y][x]=bloczek[1-kolor];
					plansza[y][x+1]=mrowkaP[kolor];
					x++;
				}
				break;
			case 'g':
				if(y !=0)
				{
					plansza[y][x]=bloczek[1-kolor];
					plansza[y-1][x]=mrowkaG[kolor];
					y--;
				}
				break;
			case 'd':
				if(y !=a)
				{
					plansza[y][x]=bloczek[1-kolor];
					plansza[y+1][x]=mrowkaD[kolor];
					y++;	
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

void obrot(int a, int b, int kolor, char* kierunek, int y_mrowki, int x_mrowki, char* plansza[a][b])
{
	if(kolor == 0)
	{
		switch(kierunek[0])
		{
				case 'l':
					plansza[y_mrowki][x_mrowki]=mrowkaD[kolor];
					*kierunek = 'd';
					break;
				case 'p':
					plansza[y_mrowki][x_mrowki]=mrowkaG[kolor];
					*kierunek = 'g';
					break;
				case 'g':
					plansza[y_mrowki][x_mrowki]=mrowkaL[kolor];
					*kierunek = 'l';
					break;
				case 'd':
					plansza[y_mrowki][x_mrowki]=mrowkaP[kolor];
					*kierunek = 'p';
					break;
		}
		
	}
	else if(kolor == 1)
	{
		switch(kierunek[0])
		{
				case 'l':
					plansza[y_mrowki][x_mrowki]=mrowkaG[kolor];
					*kierunek = 'g';
					break;
				case 'p':
					plansza[y_mrowki][x_mrowki]=mrowkaD[kolor];
					*kierunek = 'd';
					break;
				case 'g':
					plansza[y_mrowki][x_mrowki]=mrowkaP[kolor];
					*kierunek = 'p';
					break;
				case 'd':
					plansza[y_mrowki][x_mrowki]=mrowkaL[kolor];
					*kierunek = 'l';
					break;
		}
	}
}