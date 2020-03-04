# include "TXLib.h"

const int frameX = 8;
const int frameY = 5;

HDC turtImage = txLoadImage ("turtle51.bmp");
HDC mapImage  = txLoadImage ("GameMap1.bmp");
HDC bacImage  = txLoadImage ("GameBac1.bmp");


void turt_st (int x, int y, int t);
void turt_step (int *x, int *y, int t);

int frameSizeX = txGetExtentX (turtImage) / frameX;
int frameSizeY = txGetExtentY (turtImage) / frameY;
int anim = 2;
int x = 350;
int y = 350;
int t;

int main ()
{
    txCreateWindow (1000, 600);
    txBegin();

    for (int t = 0; !txGetAsyncKeyState (VK_ESCAPE); t++)
    {
    txSetFillColor (TX_BLACK);
    txClear();

    if (!GetKeyState (VK_SCROLL))
        txBitBlt (txDC (), 0, 0, 0, 0, bacImage);

    COLORREF color = txGetPixel (x + frameSizeX, y + frameSizeY);

    if (!GetKeyState (VK_CAPITAL))
        txBitBlt (txDC (), 0, 0, 0, 0, mapImage);

    turt_step (&x, &y, t);

    if (color == RGB (0, 255,   0)) anim = 4;
    if (color == RGB (0,   0, 255)) anim = 3;

    txSleep(50);
    }
    return 0;
}

void turt_st (int x, int y, int t)
{
    txTransparentBlt (txDC(), x, y, frameSizeX, frameSizeY, turtImage, (t % frameX) * frameSizeX, anim * frameSizeY, TX_RED);
    if (txGetAsyncKeyState (VK_SPACE)) anim = 2;
    if (txGetAsyncKeyState (VK_RIGHT)) anim = 0;
    if (txGetAsyncKeyState (VK_LEFT))  anim = 1;

}

void turt_step (int *x, int *y, int t)
{
    turt_st (*x, *y, t);
    int st = (GetAsyncKeyState (VK_SHIFT)? 30 : 10);
    if (txGetAsyncKeyState (VK_LEFT))  *x = *x - st;
    if (txGetAsyncKeyState (VK_RIGHT)) *x = *x + st;
    if (txGetAsyncKeyState (VK_UP))    *y = *y - st;
    if (txGetAsyncKeyState (VK_DOWN))  *y = *y + st;
}
