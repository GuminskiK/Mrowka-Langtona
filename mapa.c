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
	
	w->v[0][0] = g->LUL;
	w->v[w->m+1][0] = g->LDL;
	w->v[0][w->n+1] = g->LUR;
	w->v[(w->m+1)][(w->n+1)] = g->LDR;

	int i = 0;
	int j = 0;

	for(i = 1; i<(w->m)+1; i++){ //boczne krawedzie

		w->v[i][0] = g->LV;
	        w->v[i][w->n+1] = g->LV;

	}

	for(i=1; i<(w->n)+1; i++){ //górna i dolna krawędź

		w->v[0][i] = g->LH;
		w->v[w->m+1][i] = g->LH;

	}

	for(i=1; i<(w->m)+1; i++){ //środek
		for(int j = 1; j<(w->n)+1; j++){

			w->v[i][j] = g->W;

		}
	}
}

void gen_rand(mapa * w, znak * g, int z){
	
	srand(time(NULL)); //ziarno losowości zależne od czasu
        int k = w->m * w->n; // ile mamy pól
	int p = (z * k) / 100;//ile pól malujemy 
	int ml,nl;
        for(int i = 0; i< p; i++){
                
                los(k, &ml, &nl, w);
		while( w->v[ml][nl] != g->W){
			los(k, &ml, &nl, w);
		}
                w->v[ml][nl] = g->B;    
        }
}

void los(int k, int * ml, int * nl, mapa * w){
	
	int randomNumber = rand() % k + 1;
        if (randomNumber % w->n == 0){
                *ml = (randomNumber / w->n);
		*nl = w->n;
        }else{
        	*ml = (randomNumber / w->n)+1;
		*nl = (randomNumber % w->n);
        }

}

void czyt_mapa(FILE * W, mapa *w, znak * g, char * name){}
