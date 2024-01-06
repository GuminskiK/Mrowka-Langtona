#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>
#include <unistd.h>
#include <ctype.h>
#include "mapa.h"
#include "mrowka.h"
#include "znaki.h"
#include "druk.h"
#include "sterowanie.h"

void wczyt (int argc, char ** argv, mapa_t * mapa, mrowka_t * mrowka, znak_t * znak); //wczytywanie wartości z argv
int flagi (int argc, char ** argv); //wczytywanie flag

int main(int argc, char ** argv){ 
	
	mapa_t mapa;
	mrowka_t mrowka;
	znak_t znak;
	
	init_znaki(&znak);
	wczyt(argc, argv, &mapa, &mrowka, &znak);
	setlocale(LC_ALL, "");

	int y = 0;
	druk_mapa(&mapa, &mrowka, &znak, y);
	
	sterowanie(&mrowka, &mapa, &znak);
}

void wczyt (int argc, char ** argv, mapa_t * mapa, mrowka_t * mrowka, znak_t * znak){
	
	int f = flagi (argc, argv);

	if(f == 0){
                
        int m = argc > 1 ? atoi(argv [1]) : 8;                 //liczba wierszy planszy
        int n = argc > 2 ? atoi(argv [2]) : 10;                //liczba kolumn planszy
        char *name = argc > 4 ? argv[4] : "ML";                //przedrostek plikow wynikowych
        init_mapa(m, n, name, mapa);

        char *kierunek = argc > 5 ? argv[5] : "N";             //kierunek
        int ile = argc > 3 ? atoi(argv [3]) : 20;              //liczba iteracji
        init_mrowka(m, n, ile, kierunek, mrowka);
        gen_mapa(mapa, znak);

    } else if (f == 1){

        FILE * plik = argc > 2 ? fopen(argv[2], "r, ccs=UTF-8") : stdin;
        if(plik == NULL) perror("Nie udało się otworzyć pliku: ");

        char *nazwa = argc > 3 ? argv[3] : "ML";
        int iloscIteracji = argc > 4 ? atoi(argv[4]) : 10;

        czyt_mapa(plik, mapa, znak, nazwa, iloscIteracji, mrowka);

    } else if (f == 2){

        int m = argc > 1 ? atoi(argv [1]) : 8;                 //liczba wierszy planszy
        int n = argc > 2 ? atoi(argv [2]) : 10;                //liczba kolumn planszy
        char *name = argc > 4 ? argv[4] : "ML";                //przedrostek plikow wynikowych
        init_mapa(m, n, name, mapa);

        char *kierunek = argc > 5 ? argv[5] : "N";             //kierunek
        int ile = argc > 3 ? atoi(argv [3]) : 20;              //liczba iteracji
        init_mrowka(m, n, ile, kierunek, mrowka);
        int procent = argc > 6 ? atoi(argv[6]) : 10;                  //jaki procent
        gen_mapa(mapa, znak);
        gen_rand(mapa, znak, procent);
    }
}

int flagi (int argc, char ** argv){

	int c;

	while ((c = getopt (argc, argv, "wg")) != -1){
		
		switch (c){
		
			case 'w':
    				return 1;
    				break;
			case 'g':
    				return 2;
    				break;
			case '?':
    				fprintf (stderr, "Nieznana opcja `-%c'.\n", optopt);
    				return 0;
			default:
    				abort ();
		}
	}

	return 0;

}
