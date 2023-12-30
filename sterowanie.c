#include "sterowanie.h"

void sterowanie(mrowka * z, mapa * w, znak * g){
	
	int x = 0;

        while(z->ile != 0){

                x = ruch(z,w,g);
                if( x != 0){
                        z->ile = 0;
                }else{
                        druk_mapa(w, z, g);
			z->ile--;
                }
        }
}

