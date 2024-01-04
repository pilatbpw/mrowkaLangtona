#include "obsluga_argumentow.h"


void obsluga_argumentow(int liczba_argumentow, char *argumenty[], int* m, int* n, int* iteracje, char** nazwa_wynikowa,char** plansza_wejsciowa, char** kierunek, double* zapelnienie_procentowe){
	int opcje;
	while ((opcje = getopt(liczba_argumentow, argumenty, "w:m:n:i:p:k:z:")) != -1) {
			switch (opcje) {
				case 'w':
					if(*plansza_wejsciowa!=NULL){
						fprintf(stderr, "BLAD: Wielokrotne uzycie tego samego argumentu\n");
						exit(1);
					}
					if(optarg[0]=='-'){
						fprintf(stderr, "BLAD: Nie podano poprawnej wartosci dla argumentu -%c\n", 'w');
						exit(1);
					}
					*plansza_wejsciowa = optarg;
					break;
				case 'm':
					if(*m!=0){
						fprintf(stderr, "BLAD: Wielokrotne uzycie tego samego argumentu\n");
						exit(1);
					}
					if(optarg[0]=='-'){
						fprintf(stderr, "BLAD: Nie podano poprawnej wartosci dla argumentu -%c\n", 'm');
						exit(1);
					}
					*m = atoi(optarg);
					break;
				case 'n':
					if(*n!=0){
						fprintf(stderr, "BLAD: Wielokrotne uzycie tego samego argumentu\n");
						exit(1);
					}
					if(optarg[0]=='-'){
						fprintf(stderr, "BLAD: Nie podano poprawnej wartosci dla argumentu -%c\n", 'n');
						exit(1);
					}
					*n = atoi(optarg);
					break;
				case 'i':
					if(*iteracje!=0){
						fprintf(stderr, "BLAD: Wielokrotne uzycie tego samego argumentu\n");
						exit(1);
					}
					if(optarg[0]=='-'){
						fprintf(stderr, "BLAD: Nie podano poprawnej wartosci dla argumentu -%c\n", 'i');
						exit(1);
					}
					*iteracje = atoi(optarg);
					break;
				case 'p':
					if(*nazwa_wynikowa!=NULL){
						fprintf(stderr, "BLAD: Wielokrotne uzycie tego samego argumentu\n");
						exit(1);
					}
					if(optarg[0]=='-'){
						fprintf(stderr, "BLAD: Nie podano poprawnej wartosci dla argumentu -%c\n", 'p');
						exit(1);
					}
					*nazwa_wynikowa = optarg;
					break;
				case 'k':
					if(*kierunek!=NULL){
						fprintf(stderr, "BLAD: Wielokrotne uzycie tego samego argumentu\n");
						exit(1);
					}
					if(optarg[0]=='-'){
						fprintf(stderr, "BLAD: Nie podano poprawnej wartosci dla argumentu -%c\n", 'k');
						exit(1);
					}
					*kierunek = optarg;
					break;
				case 'z':
					if(*zapelnienie_procentowe!=0.0){
						fprintf(stderr, "BLAD: Wielokrotne uzycie tego samego argumentu\n");
						exit(1);
					}
					if(optarg[0]=='-'){
						fprintf(stderr, "BLAD: Nie podano poprawnej wartosci dla argumentu -%c\n", 'z');
						exit(1);
					}
					*zapelnienie_procentowe = atof(optarg);
					if(*zapelnienie_procentowe>1.0){
						fprintf(stderr, "BLAD: Podano zbyt duza wartosc zapelnienia: %f\n", *zapelnienie_procentowe);
						exit(1);
					}
					break;
				case '?':
					if(optopt == 'm' ||optopt == 'n' ||optopt == 'i' ||optopt == 'p' ||optopt == 'k' || optopt =='w' || optopt =='z'){
						fprintf(stderr, "BLAD: Nie podano wartosci dla argumentu -%c\n", optopt);
						exit(1);
					
					}
					fprintf(stderr, "BLAD: Nieznana opcja %c\n", optopt);
				
					break;
				default:
					fprintf(stderr, "BLAD: Niepoprawna opcja: %c\n", optopt);
					break;
			}
		
			if (opcje == '?') {
				break;
			}
		}
		
		if(*kierunek==NULL && *plansza_wejsciowa==NULL){
			fprintf(stderr, "BLAD: Nie podano kierunku startowego mrowki\n");
			exit(1);
		}
		if(*plansza_wejsciowa!=NULL && (*m!=0 || *n!=0 || *kierunek!=NULL || *zapelnienie_procentowe!=0.0)){
			fprintf(stderr, "BLAD: Niepoprawne wprowadzenie argumentow\n(Uzyto jednoczenie -w oraz -m, -n, -k lub -z)\n");
			exit(1);
		}
	printf("Opcje m=%i n=%i iteracje=%i nazwa_wynikowa=%s kierunek=%s\n", *m, *n, *iteracje, *nazwa_wynikowa, *kierunek);
}
