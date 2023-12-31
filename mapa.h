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

	wchar_t ***v; //mapa w postaci dwuwymiarowej tablicy przechowującej znaki, które są same w sobie tablicami
	int m; //ilość rzędów mapy
	int n; //ilość kolumn mapy
	char * name; //początek nazwy pliku wyjściowego

}mapa;

void init_mapa(int m, int n, char * name, mapa * w); //malloc i przypisanie wartości zmiennym ze struktury

void gen_mapa(mapa * w, znak * g); //generowanie mapy

void gen_rand(mapa * w, znak * g, int z);

void czyt_mapa(FILE * W, mapa *w, znak * g, char * name);

void los(int k, int * ml, int * nl, mapa * w);
#endif
