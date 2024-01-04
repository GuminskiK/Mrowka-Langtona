#include "znaki.h"

void init_znaki(znak_t * znak){
	
	//strzałki
    znak->AWN = L"△"; //A-arrow, W-white, N-north
    znak->ABN = L"▲";

    znak->AWE = L"▷";
    znak->ABE = L"▶";

    znak->AWS = L"▽";
    znak->ABS = L"▼";

    znak->AWW = L"◁";
    znak->ABW = L"◀";

    //ramka

    znak->LV = L"│"; //L-line, V-vertical
    znak->LH = L"─";
    znak->LUL = L"┌"; //L-line, D-down, R-right
    znak->LUR = L"┐";
    znak->LDL = L"└";
    znak->LDR = L"┘";

    //pola
    znak->W = L" ";
    znak->B = L"█";
}
