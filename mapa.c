#include "mapa.h"
#include "mrowka.h"
#include "znaki.h"
#include "wchar.h"
#define MAX_LINIA 500

void init_mapa(int wiersze, int kolumny, char * nazwa, mapa_t * mapa){

	//w->m = malloc(sizeof(int));
	mapa->wiersze = wiersze;

	//w->n = malloc(sizeof(int));
	mapa->kolumny = kolumny;

    mapa->nazwa = malloc(sizeof(char) * strlen(nazwa));
    mapa->nazwa = nazwa;

    mapa->plansza = (wchar_t **)malloc((wiersze + 2) * sizeof (wchar_t*));

	for(int i = 0; i< (wiersze + 2); i++){
        mapa->plansza[i] = (wchar_t*)malloc((kolumny + 2) * sizeof(wchar_t));
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

void znajdzMrowke(wchar_t* linia, znak_t* znaki, int ileIteracji, mrowka_t* mrowka, int wiersz){
    // Znaki poukladane w kolejnosci NESWNESW
    wchar_t glowy[8] = {
            znaki->ABN, znaki->ABE, znaki->ABS, znaki->ABW,  // Przeźroczyste
            znaki->AWN, znaki->AWE, znaki->AWS, znaki->AWW
    };
    char kierunki[4] = {'N', 'E', 'S', 'W'};

    for(int glowaIndex = 0; glowaIndex < 8; glowaIndex++) {
        wchar_t glowa = glowy[glowaIndex];
        // Jeżeli znaleziono
        wchar_t * wskaznikNaMrowke = wcschr(linia, glowa);
        if (wskaznikNaMrowke != NULL)
        {
            int kolumna = wskaznikNaMrowke - linia;
            char kierunek = kierunki[glowaIndex % 4];

            mrowka->wiersz = wiersz;
            mrowka->kolumna = kolumna;
            mrowka->ile = ileIteracji;
            mrowka->kierunek = kierunek;
        }
    }

}

//z pliku może poznać wymiary
void czyt_mapa(FILE * plik, mapa_t *mapa, znak_t * znak, char * nazwa, int ileIteracji, mrowka_t* mrowka){
    setlocale(LC_ALL, "");

    wchar_t linia[MAX_LINIA] = L"";

    // Sprawdź długość pierwszej linii (ramki)
    fgetws(linia, MAX_LINIA, plik);


    int iloscKolumn = wcslen(linia) - 3; // bo trzeba usunąć też znak nowej linii
    int iloscWierszy = 0;

    // Licz wiersze
    while(fgetws(linia, MAX_LINIA, plik) != NULL) {
        // wykrywa to dolną ramkę
        if(wcschr(linia, znak->LV) == NULL) break;
        iloscWierszy++;
    }
    init_mrowka(iloscWierszy, iloscWierszy, ileIteracji, "N", mrowka);
    init_mapa(iloscWierszy, iloscKolumn, nazwa, mapa);

    // Używam tego aby pominąć wszyskie białe znaki przed ramką
    rewind(plik);
    // Zaczynam od indeksu
    for(int wiersz = 0; wiersz <= iloscWierszy + 1; wiersz++) {
        fgetws(linia, MAX_LINIA, plik);
        linia[iloscKolumn + 2] = '\0';
        znajdzMrowke(linia, znak, ileIteracji, mrowka, wiersz);
        wcsncpy(mapa->plansza[wiersz], linia, iloscKolumn + 3);
    }
}
