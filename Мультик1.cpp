#include "TXLib.h"
#include "TX_MY_Lib.cpp"

int main ()
{
    txCreateWindow (1000, 700);
    txClear ();
    int t = 0;
    int r, g, b;

    drawTitry (600);
    drawScreen (1);
    while (t <= 40)
    {
        txClear ();
        ClearSpace();
        drawBob (650 - 5*t, 250, 1.1, 1.1, 1, 0, 0, 0, t);
        t += 1;
        txSleep (30);
    }
    drawMirBob();
    drawScreen (2);
    drawPortal(500, 350, 300, 7, r, g, b);
    drawScreen (3);
    drawCat (1000, 300);
    drawSpots1 (100, 300) ;
    drawBob (700, 250, 1.1, 1.1, 1, 0, 0, 0, 0);
    drawSpots (610, 130);



    return 0;
}
