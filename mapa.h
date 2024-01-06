#ifndef __MAPA_H__
#define __MAPA_H__

#include <stdlib.h>
#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include <string.h>
#include <time.h>
#include "znaki.h"


typedef struct {

	wchar_t **plansza; //mapa w postaci dwuwymiarowej tablicy przechowującej znaki, które są same w sobie tablicami
	int wiersze; //ilość rzędów mapy
	int kolumny; //ilość kolumn mapy
	char * nazwa; //początek nazwy pliku wyjściowego

} mapa_t;

#include "mrowka.h"

void init_mapa(int wiersze, int kolumny, char * nazwa, mapa_t * mapa); //malloc i przypisanie wartości zmiennym ze struktury

void gen_mapa(mapa_t * mapa, znak_t * znak); //generowanie mapy

void gen_rand(mapa_t * mapa, znak_t * znak, int procent);

void czyt_mapa(FILE * plik, mapa_t *mapa, znak_t * znak, char * nazwa, int ileIteracji, mrowka_t* mrowka);

void los(int iloscKomorek, int * wiersz, int * kolumna, mapa_t * mapa);

#endif
