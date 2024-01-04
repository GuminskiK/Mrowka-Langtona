#include "mapa.h"

void init_mapa(int m, int n, char * nazwa, mapa_t * mapa){

	//w->m = malloc(sizeof(int));
	mapa->wiersze = m;

	//w->n = malloc(sizeof(int));
	mapa->kolumny = n;

    mapa->nazwa = malloc(sizeof(char) * strlen(nazwa));
    mapa->nazwa = nazwa;

    mapa->plansza = (wchar_t **)malloc((m + 2) * sizeof (wchar_t*));

	for(int i = 0; i< (m+2); i++){

        mapa->plansza[i] = (wchar_t*)malloc((n + 2) * sizeof(wchar_t));
	}
}

void gen_mapa(mapa_t * mapa, znak_t * znak){

    mapa->plansza[0][0] = znak->LUL;
    mapa->plansza[mapa->wiersze + 1][0] = znak->LDL;
    mapa->plansza[0][mapa->kolumny + 1] = znak->LUR;
    mapa->plansza[(mapa->wiersze + 1)][(mapa->kolumny + 1)] = znak->LDR;

	int i = 0;
	int j = 0;

	for(i = 1; i< (mapa->wiersze) + 1; i++){ //boczne krawedzie

		mapa->plansza[i][0] = znak->LV;
        mapa->plansza[i][mapa->kolumny + 1] = znak->LV;

	}

	for(i=1; i< (mapa->kolumny) + 1; i++){ //górna i dolna krawędź

		mapa->plansza[0][i] = znak->LH;
        mapa->plansza[mapa->wiersze + 1][i] = znak->LH;

	}

	for(i=1; i< (mapa->wiersze) + 1; i++){ //środek
		for(int j = 1; j< (mapa->kolumny) + 1; j++){

            mapa->plansza[i][j] = znak->W;

		}
	}
}

void gen_rand(mapa_t * mapa, znak_t * znak, int procent){
	
	srand(time(NULL)); //ziarno losowości zależne od czasu
    int iloscKomorek = mapa->wiersze * mapa->kolumny; // ile mamy pól
	int polaDoZamalowania = (procent * iloscKomorek) / 100;//ile pól malujemy
	int wylosowanyWiersz,wylosowanaKolumna;
        for(int i = 0; i < polaDoZamalowania; i++){
            los(iloscKomorek, &wylosowanyWiersz, &wylosowanaKolumna, mapa);
		    while(mapa->plansza[wylosowanyWiersz][wylosowanaKolumna] != znak->W){
			    los(iloscKomorek, &wylosowanyWiersz, &wylosowanaKolumna, mapa);
		    }
            mapa->plansza[wylosowanyWiersz][wylosowanaKolumna] = znak->B;
        }
}

void los(int iloscKomorek, int * wiersz, int * kolumna, mapa_t * mapa){
	
	int wylosowanyNumer = rand() % iloscKomorek + 1;
        if (wylosowanyNumer % mapa->kolumny == 0){
            *wiersz = (wylosowanyNumer / mapa->kolumny);
		    *kolumna = mapa->kolumny;
        }
        else{
        	*wiersz = (wylosowanyNumer / mapa->kolumny) + 1;
		    *kolumna = (wylosowanyNumer % mapa->kolumny);
        }

}

void czyt_mapa(FILE * plik, mapa_t *mapa, znak_t * znak, char * nazwa){}
