#include "druk.h"

void mrowka_pok(mapa_t * mapa, mrowka_t * mrowka, znak_t * znak){
	if (mapa->plansza[mrowka->wiersz][mrowka->kolumna] == znak->W){
        switch (mrowka->kierunek){
            case 'N':
                mapa->plansza[mrowka->wiersz][mrowka->kolumna] = znak->AWN;
                break;
            case 'E':
                mapa->plansza[mrowka->wiersz][mrowka->kolumna] = znak->AWE;
                break;
            case 'S':
                mapa->plansza[mrowka->wiersz][mrowka->kolumna] = znak->AWS;
                break;
            case 'W':
                mapa->plansza[mrowka->wiersz][mrowka->kolumna] = znak->AWW;
                break;
        }
	}
    else if(mapa->plansza[mrowka->wiersz][mrowka->kolumna] == znak->B) {
        switch (mrowka->kierunek){
            case 'N':
                mapa->plansza[mrowka->wiersz][mrowka->kolumna] = znak->ABN;
                break;
            case 'E':
                mapa->plansza[mrowka->wiersz][mrowka->kolumna] = znak->ABE;
                break;
            case 'S':
                mapa->plansza[mrowka->wiersz][mrowka->kolumna] = znak->ABS;
                break;
            case 'W':
                mapa->plansza[mrowka->wiersz][mrowka->kolumna] = znak->ABW;
                break;
        }
	}
}

void mrowka_ukr(mapa_t * mapa, mrowka_t * mrowka, znak_t * znak){
	// Jeśli pole puste
	if(mapa->plansza[mrowka->wiersz][mrowka->kolumna] == znak->AWN
    || mapa->plansza[mrowka->wiersz][mrowka->kolumna] == znak->AWE
    || mapa->plansza[mrowka->wiersz][mrowka->kolumna] == znak->AWS
    || mapa->plansza[mrowka->wiersz][mrowka->kolumna] == znak->AWW)
    {
        mapa->plansza[mrowka->wiersz][mrowka->kolumna] = znak->W;

	}
    // Jeśli pole białe
    else if(mapa->plansza[mrowka->wiersz][mrowka->kolumna] == znak->ABN
         || mapa->plansza[mrowka->wiersz][mrowka->kolumna] == znak->ABE
         || mapa->plansza[mrowka->wiersz][mrowka->kolumna] == znak->ABS
         || mapa->plansza[mrowka->wiersz][mrowka->kolumna] == znak->ABW)
    {
        mapa->plansza[mrowka->wiersz][mrowka->kolumna] = znak->B;

	}
}

void druk_mapa(mapa_t * mapa, mrowka_t * mrowka, znak_t * znak, int numerKroku){

	int i,j;

	mrowka_pok(mapa, mrowka, znak);
	
	FILE * druk;
	char filename[strlen(mapa->nazwa) + 5];
	sprintf(filename, "%s_%i", mapa->nazwa, numerKroku);

	druk = fopen(filename,"w");
	

    for(i=0; i<(mapa->wiersze + 2); i++){
        fwprintf(druk, L"%ls\n", mapa->plansza[i]);
    }
    mrowka_ukr(mapa, mrowka, znak);
}
