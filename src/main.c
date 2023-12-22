#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int opcje;
    int m = 0;  // Liczba wierszy
    int n = 0;  // Liczba kolumn
    int iteracje = 0;  // Liczba iteracji
    char *nazwa_wynikowa = NULL;  // Nazwa plików wynikowych
    char *kierunek = NULL;  // Kierunek początkowy mrowki g - gora d -dol p - prawo l - lewo

    while ((opcje = getopt(argc, argv, "m:n:i:p:k:")) != -1) {
        switch (opcje) {
            case 'm':
				if(m!=0){
					fprintf(stderr, "BLAD: Wielokrotne uzycie tego samego argumentu\n");
					exit(1);
				}
				if(optarg[0]=='-'){
					fprintf(stderr, "Nie podano poprawnej wartosci dla argumentu -%c\n", 'm');
					exit(1);
				}
                m = atoi(optarg);
                break;
            case 'n':
				if(n!=0){
					fprintf(stderr, "BLAD: Wielokrotne uzycie tego samego argumentu\n");
					exit(1);
				}
				if(optarg[0]=='-'){
					fprintf(stderr, "Nie podano poprawnej wartosci dla argumentu -%c\n", 'n');
					exit(1);
				}
                n = atoi(optarg);
                break;
            case 'i':
				if(iteracje!=0){
					fprintf(stderr, "BLAD: Wielokrotne uzycie tego samego argumentu\n");
					exit(1);
				}
				if(optarg[0]=='-'){
					fprintf(stderr, "Nie podano poprawnej wartosci dla argumentu -%c\n", 'i');
					exit(1);
				}
                iteracje = atoi(optarg);
                break;
            case 'p':
				if(nazwa_wynikowa!=NULL){
					fprintf(stderr, "BLAD: Wielokrotne uzycie tego samego argumentu\n");
					exit(1);
				}
				if(optarg[0]=='-'){
					fprintf(stderr, "Nie podano poprawnej wartosci dla argumentu -%c\n", 'p');
					exit(1);
				}
                nazwa_wynikowa = optarg;
                break;
            case 'k':
				if(kierunek!=NULL){
					fprintf(stderr, "BLAD: Wielokrotne uzycie tego samego argumentu\n");
					exit(1);
				}
				if(optarg[0]=='-'){
					fprintf(stderr, "Nie podano poprawnej wartosci dla argumentu -%c\n", 'k');
					exit(1);
				}
                kierunek = optarg;
                break;
			
            case '?':
				if(optopt == 'm' ||optopt == 'n' ||optopt == 'i' ||optopt == 'p' ||optopt == 'k'){
					fprintf(stderr, "Nie podano wartosci dla argumentu -%c\n", optopt);
					exit(1);
					
				}
                fprintf(stderr, "Nieznana opcja %c\n", optopt);
				
                break;
            default:
                fprintf(stderr, "Niepoprawna opcja: %c\n", optopt);
                break;
        }
		
        if (opcje == '?') {
            break;
        }
    }

    printf("Opcje m=%i n=%i iteracje=%i nazwa_wynikowa=%s kierunek=%s\n", m, n, iteracje, nazwa_wynikowa, kierunek);
    return 0;
}
