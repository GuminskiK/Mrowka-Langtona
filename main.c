#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>
#include <unistd.h>
#include "mapa.h"
#include "mrowka.h"
#include "znaki.h"
#include "druk.h"
#include "sterowanie.h"

void wczyt (int argc, char ** argv, mapa * w, mrowka * z); //wczytywanie wartości z argv
int flagi (int argc, char ** argv); //wczytywanie flag

int main(int argc, char ** argv){ 
	
	mapa w;
	mrowka z;
	znak g;
	
	init_znaki(&g);
	wczyt(argc, argv, &w, &z);
	int f = flagi(argc,argv);

	setlocale(LC_ALL, "C.UTF-8");

	gen_mapa(&w, &g);
	int y = 0;
	druk_mapa(&w, &z, &g, y);
	
	sterowanie(&z, &w, &g);
}

void wczyt (int argc, char ** argv, mapa * w, mrowka * z){

	int m = argc > 1 ? atoi(argv [1]) : 8;                 //liczba wierszy planszy
        int n = argc > 2 ? atoi(argv [2]) : 10;                //liczba kolumn planszy
        char *name = argc > 4 ? argv[4] : "ML";                //przedrostek plikow wynikowych
	init_mapa( m, n, name, w);

        char *kierunek = argc > 5 ? argv[5] : "N";	       //kierunek
	int ile = argc > 3 ? atoi(argv [3]) : 20;              //liczba iteracji
	init_mrowka( m, n, ile, kierunek, z);

}

int flagi(int argc, char ** argv){
	
	int c; 

	while((c = getopt(argc, argv, "wg")) != 1){
	
		switch(c){
			case 'w':
				return 1;
				break;
			case 'g':
				return 2;
				break;
			case '?':
				fprintf(stderr, "Nie rozpoznano flagi: %c \n", optopt);
				break;
		}
	}

	return 0;

}
