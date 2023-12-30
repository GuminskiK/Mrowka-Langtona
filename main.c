#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>
#include "mapa.h"
#include "mrowka.h"
#include "znaki.h"
#include "druk.h"

void wczyt (int argc, char ** argv, mapa * w, mrowka * z); //wczytywanie wartości z argv

int main(int argc, char ** argv){ 
	
	mapa w;
	mrowka z;
	znak g;

	wczyt(argc, argv, &w, &z);
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