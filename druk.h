#ifndef __DRUK_H__
#define __DRUK_H__
#include "znaki.h"
#include "mapa.h"
#include "mrowka.h"


void druk_mapa(mapa_t * mapa, mrowka_t * mrowka, znak_t * znak, int numerKroku); //wydrukowanie mapy
void mrowka_pok(mapa_t * mapa, mrowka_t * mrowka, znak_t * znak); //umieszczenie odpowiedniej mrówki na mapie
void mrowka_ukr(mapa_t * mapa, mrowka_t * mrowka, znak_t * znak); //usunięcie mrówki z mapy
#endif
