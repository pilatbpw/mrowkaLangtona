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
			printf("Udana funkcja kolor\n");
			if(kolor_ == 0)
			{
				printf("rozpoczenie funkcja obrot\n");
				obrot(a, b, kolor_, &kierunek, y_mrowki, x_mrowki, plansza);
				printf("Udana funkcja obrot\n");
				//printf("kierunek %s \n", kierunek);
				naprzod(a, b, kolor_, kierunek, &y_mrowki, &x_mrowki, plansza);
				printf("Udana funkcja naprzod\n");
			}
			else if (kolor_ == 1)
			{
				obrot(a, b, kolor_, &kierunek, y_mrowki, x_mrowki, plansza);
				printf("Udana funkcja obrot\n");
				//printf("kierunek %s \n", kierunek);
				naprzod(a, b, kolor_, kierunek, &y_mrowki, &x_mrowki, plansza);
				printf("Udana funkcja naprzod\n");
			}
			else
			{
				printf("BLAD!!!!!!");
			}
				printf("Udane poruszenie sie mrowki\n");
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

void obrot(int a, int b, int kolor, char** kierunek, int y_mrowki, int x_mrowki, char* plansza[a][b])
{
	printf("argumenty: a=%d b=%d kolor=%d kierunek=%s y_mrowki=%d x_mrowki=%d plansza[a][b]=%s\n", a, b, kolor, *kierunek, y_mrowki, x_mrowki, plansza[a][b]);
	printf("mrowkaD=%s %s mrowkaG=%s %s mrowkaL=%s %s mrowkaP=%s %s bloczek=%s %s\n", mrowkaD[0],mrowkaD[1],mrowkaG[0], mrowkaG[1], mrowkaL[0], mrowkaL[1], mrowkaP[0], mrowkaP[1], bloczek[0], bloczek[1]);
	
	if(kolor == 0)
	{
		printf("Proba wypisania testowego plansza[a][b]\n");
		printf("%s\n", plansza[y_mrowki][x_mrowki]);
		
		switch((*kierunek)[0])
		{
				case 'l':
				printf("test\n");
					plansza[y_mrowki][x_mrowki]=mrowkaD[kolor];
					printf("test1\n");
					*kierunek = "d";
					printf("test2\n");
					break;
				case 'p':
				printf("test\n");
					plansza[y_mrowki][x_mrowki]=mrowkaG[kolor];
					printf("test1\n");
					*kierunek = "g";
					printf("test2\n");
					break;
				case 'g':
				printf("test\n");
					plansza[y_mrowki][x_mrowki]=mrowkaL[kolor];
					printf("test1\n");
					*kierunek = "l";
					printf("test2\n");
					break;
				case 'd':
				printf("test\n");
					plansza[y_mrowki][x_mrowki]=mrowkaP[kolor];
					printf("test1\n");
					*kierunek = "p";
					printf("test2\n");
					break;
		}
		printf("Udana switch\n");

		printf("Udane przypisanie kierunku\n");
	}
	else if(kolor == 1)
	{
		
		switch((*kierunek)[0])
		{
				case 'l':
				printf("test\n");
					plansza[y_mrowki][x_mrowki]=mrowkaG[kolor];
					printf("test1\n");
					*kierunek = "g";
					printf("test2\n");
					break;
					
				case 'p':
				printf("test\n");
					plansza[y_mrowki][x_mrowki]=mrowkaD[kolor];
					printf("test1\n");
					*kierunek = "d";
					printf("test2\n");
					break;
				case 'g':
				printf("test\n");
					plansza[y_mrowki][x_mrowki]=mrowkaP[kolor];
					printf("test1\n");
					*kierunek = "p";
					printf("test2\n");
					break;
				case 'd':
				printf("test\n");
					plansza[y_mrowki][x_mrowki]=mrowkaL[kolor];
					printf("test1\n");
					*kierunek = "l";
					printf("test2\n");
					break;
		}
		printf("Udana switch\n");
	}
}