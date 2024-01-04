#ifndef __MROWA_H__
#define __MROWA_H__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mapa.h"
#include "znaki.h"

typedef struct{

	char kierunek; //litera oznaczająca kierunek, w który mrówka jest skierowana
	int wiersz; // rząd w którym mrówka się znajduje
	int kolumna; // kolumna w której mrówka się znajduje
	int ile; //pozostała ilość iteracji

} mrowka_t;

void init_mrowka(int wiersze, int kolumny, int ile, char * kierunek, mrowka_t * mrowka); //malloc i przypisanie wartości zmiennym ze struktury
int ruch(mrowka_t * mrowka, mapa_t * mapa, znak_t * znak); //ruch mrówki

#endif
