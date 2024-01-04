#include "mrowka.h"

void init_mrowka(int wiersze, int kolumny, int ile, char * kierunek, mrowka_t * mrowka){
	
	//z->kierunek = malloc(sizeof(char));
	mrowka->kierunek = kierunek[0];

	//z->mp = malloc(sizeof(int));
	mrowka->wiersz = (int)(wiersze / 2);

	//z->np = malloc(sizeof(int));
	mrowka->kolumna = (int)(kolumny / 2);

    mrowka->ile = ile;

}

int ruch(mrowka_t * mrowka, mapa_t * mapa, znak_t * znak){
	
	if (mapa->plansza[mrowka->wiersz][mrowka->kolumna] == znak->W){

        mapa->plansza[mrowka->wiersz][mrowka->kolumna] = znak->B;

		switch (mrowka->kierunek){
			case 'N':
                mrowka->kierunek = 'E';
                mrowka->kolumna += 1;
				break;
			case 'E':
                mrowka->kierunek = 'S';
                mrowka->wiersz += 1;
				break;
			case 'S':
                mrowka->kierunek = 'W';
                mrowka->kolumna -= 1;
				break;
			case 'W':
                mrowka->kierunek = 'N';
                mrowka->wiersz -= 1;
				break;
		}


	}
    else if(mapa->plansza[mrowka->wiersz][mrowka->kolumna] == znak->B){

        mapa->plansza[mrowka->wiersz][mrowka->kolumna] = znak->W;

        switch (mrowka->kierunek){
            case 'N':
                mrowka->kierunek = 'W';
                mrowka->kolumna -= 1;
                break;
            case 'E':
                mrowka->kierunek = 'N';
                mrowka->wiersz -= 1;
                break;
            case 'S':
                mrowka->kierunek = 'E';
                mrowka->kolumna += 1;
                break;
            case 'W':
                mrowka->kierunek = 'S';
                mrowka->wiersz += 1;
                break;
        }

	}
    else
    {
		return 1;

	}

	return 0;
}
