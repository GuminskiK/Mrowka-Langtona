#include "znaki.h"

void init_znaki(znak * g){
	
	//strzałki
        g->AWN = L"△"; //A-arrow, W-white, N-north
        g->ABN = L"▲";

        g->AWE = L"▷";
        g->ABE = L"▶";

        g->AWS = L"▽";
        g->ABS = L"▼";

        g->AWW = L"◁";
        g->ABW = L"◀";

        //ramka

        g->LV = L"│"; //L-line, V-vertical
        g->LH = L"─";
        g->LUL = L"┌"; //L-line, D-down, R-right
        g->LUR = L"┐";
        g->LDL = L"└";
        g->LDR = L"┘";

        //pola
        g->W = L" ";
        g->B = L"█";
}
