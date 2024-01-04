#include "sterowanie.h"

void sterowanie(mrowka_t * z, mapa_t * w, znak_t * g){
	
	int x = 0; //zmienna do sprawdzania czy nie weszliśmy na ramkę
	int y = 1; //numer pliku, do którego drukujemy
    while(z->ile != 0){
        x = ruch(z,w,g);
        if( x != 0){
                z->ile = 0;
        }
        else{
            druk_mapa(w, z, g, y);
            z->ile--;
            y++;
        }
    }
}

