#include "mrowka.h"

void init_mrowka(int m, int n, int ile, char * kierunek, mrowka * z){
	
	//z->kierunek = malloc(sizeof(char));
	z->kierunek = kierunek[0];

	//z->mp = malloc(sizeof(int));
	z->mp = (int)(m/2);

	//z->np = malloc(sizeof(int));
	z->np = (int)(n/2);

	z->ile = ile;

}

int ruch(mrowka * z, mapa * w, znak * g){
	
	if (w->v[z->mp][z->np] == g->W){

		w->v[z->mp][z->np] = g->B;

		switch (z->kierunek){
			case 'N':
				z->kierunek = 'E';
				z->np += 1;
				break;
			case 'E':
				z->kierunek = 'S';
				z->mp += 1;
				break;
			case 'S':
				z->kierunek = 'W';
				z->np -= 1;
				break;
			case 'W':
				z->kierunek = 'N';
				z->mp -= 1;
				break;
		}


	}else if(w->v[z->mp][z->np] == g->B){

		w->v[z->mp][z->np] = g->W;

                switch (z->kierunek){
                        case 'N':
                                z->kierunek = 'W';
                                z->np -= 1;
                                break;
                        case 'E':
                                z->kierunek = 'N';
                                z->mp -= 1;
                                break;
                        case 'S':
                                z->kierunek = 'E';
                                z->np += 1;
                                break;
                        case 'W':
                                z->kierunek = 'S';
                                z->mp += 1;
                                break;
                }

	}else{
		return 1;

	}

	return 0;
}
