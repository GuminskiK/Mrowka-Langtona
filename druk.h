#ifndef __DRUK_H__
#define __DRUK_H__
#include "znaki.h"
#include "mapa.h"
#include "mrowka.h"


void druk_mapa(mapa * w, mrowka * z, znak * g, int y); //wydrukowanie mapy
void mrowka_pok(mapa * w, mrowka * z, znak * g); //umieszczenie odpowiedniej mrówki na mapie
void mrowka_ukr(mapa * w, mrowka * z, znak * g); //usunięcie mrówki z mapy
#endif
