#include "mapa.h"

void init_mapa( int m, int n, char * name, mapa * w){

	//w->m = malloc(sizeof(int));
	w->m = m;

	//w->n = malloc(sizeof(int));
	w->n = n;

	w->name = malloc(sizeof(char) * strlen(name));
	w->name = name;	
	
	w->v = (wchar_t ***)malloc((m+2) * sizeof (wchar_t**));

	for(int i = 0; i< (m+2); i++){

		w->v[i] = (wchar_t**)malloc((n+2) * sizeof(wchar_t*));
	}
}

void gen_mapa(mapa * w, znak * g){

}
