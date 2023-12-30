#ifndef __MROWA_H__
#define __MROWA_H__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mapa.h"
#include "znaki.h"

typedef struct{

	char kierunek; //litera oznaczająca kierunek, w który mrówka jest skierowana
	int mp; // rząd w którym mrówka się znajduje
	int np; // kolumna w której mrówka się znajduje
	int ile; //pozostała ilość iteracji

} mrowka;

void init_mrowka( int m, int n, int ile, char * kierunek, mrowka * z); //malloc i przypisanie wartości zmiennym ze struktury
void ruch(mrowka * z, mapa * w, znak * g); //ruch mrówki

#endif
