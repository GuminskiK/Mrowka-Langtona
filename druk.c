#include "druk.h"

void mrowka_pok(mapa * w, mrowka * z, znak * g){

	if (w->v[z->mp][z->np] == g->W){

                switch (z->kierunek){
                        case 'N':
                                w->v[z->mp][z->np] = g->AWN;
                                break;
                        case 'E':
                                w->v[z->mp][z->np] = g->AWE;
                                break;
                        case 'S':
                                w->v[z->mp][z->np] = g->AWS;
                                break;
                        case 'W':
                                w->v[z->mp][z->np] = g->AWW;
                                break;
                }
	} else if(w->v[z->mp][z->np] == g->B) {

                switch (z->kierunek){
                        case 'N':
                                w->v[z->mp][z->np] = g->ABN;
                                break;
                        case 'E':
                                w->v[z->mp][z->np] = g->ABE;
                                break;
                        case 'S':
                                w->v[z->mp][z->np] = g->ABS;
                                break;
                        case 'W':
                                w->v[z->mp][z->np] = g->ABW;
                                break;
           	}
	}
}

void mrowka_ukr(mapa * w, mrowka * z, znak * g){
	
	if(w->v[z->mp][z->np] == g->AWN ||w->v[z->mp][z->np] == g->AWE || w->v[z->mp][z->np] == g->AWS || w->v[z->mp][z->np] == g->AWW){
		w->v[z->mp][z->np] = g->W;

	}else if(w->v[z->mp][z->np] == g->ABN ||w->v[z->mp][z->np] == g->ABE || w->v[z->mp][z->np] == g->ABS || w->v[z->mp][z->np] == g->ABW){
		w->v[z->mp][z->np] = g->B;

	}
}

void druk_mapa(mapa * w, mrowka * z, znak * g, int y){

	int i,j;

	mrowka_pok(w,z,g);
	
	FILE * druk;
	char filename[strlen(w->name) + 5];
	sprintf(filename, "%s.%i", w->name, y);

	druk = fopen(filename,"w");
	

        for(i=0; i<(w->m+2);i++){
                fprintf(druk,"\n");
                for(j=0; j<(w->n+2); j++){

                       fprintf(druk, "%ls", w->v[i][j]);

                }
        }

        mrowka_ukr(w,z,g);
}
