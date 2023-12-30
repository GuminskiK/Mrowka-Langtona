#ifndef __ZNAKI_H__
#define __ZNAKI_H__

#include <stdlib.h>
#include <stdio.h>

typedef struct{
	
	//strzałki
        wchar_t *AWN; //A-arrow, W-white, N-north
        wchar_t *ABN;

        wchar_t *AWE;
        wchar_t *ABE;

        wchar_t *AWS;
        wchar_t *ABS;

        wchar_t *AWW;
        wchar_t *ABW;

        //ramka

        wchar_t *LV; //L-line, V-vertical
        wchar_t *LH;
        wchar_t *LUL; //L-line, D-down, R-right
        wchar_t *LUR;
        wchar_t *LDL;
        wchar_t *LDR;

        //pola
        wchar_t *W;
        wchar_t *B;
} znak;

void init_znaki(znak * g); //przypisanie wartości zmiennym ze struktury


#endif
