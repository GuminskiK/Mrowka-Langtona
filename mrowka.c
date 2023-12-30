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

void ruch(mrowka * z, mapa * w, znak * g){

}
