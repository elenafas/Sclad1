# include "TXLib.h"

void PlayBall (int x, int y, COLORREF color);
void Phisics (int *x, int *y, int *vx, int *vy);
void drawCar (int x, int y);
void MooveCar (int *xc, int yc);

struct  balls
{
    int x; int y;
    int vx; int vy;
    int r, g, b;
    bool put;
};

int main()
{
    int x2 = 500, y2 = 500;
    char st[11];
    int k = 0;
    int sizeX = 1000;
    int sizeY = 600;
    int i;
    int count = 0;

    txCreateWindow (sizeX, sizeY);
    txBegin();
    int n = 3;
    balls a[n];
    for (i = 0; i < n; i++)
    {
        a[i].x  = rand() % sizeX;
        a[i].y  = 10;
        a[i].vx = rand() % 15;
        a[i].vy = rand() % 15;
        a[i].r = rand() % 256 + 1;
        a[i].g = rand() % 256 + 1;
        a[i].b = rand() % 256 + 1;
        a[i].put = false;
    }

    while (!txGetAsyncKeyState (VK_ESCAPE))
    {
        txSetFillColor(TX_WHITE);
        txClear();
        MooveCar (&x2, y2);
        for (i = 0; i < n; i++)
        {
            PlayBall ( a[i].x,   a[i].y, RGB (a[i].r, a[i].g, a[i].b));
            Phisics  (&a[i].x, &a[i].y,  &a[i].vx,  &a[i].vy);
            if ((y2 - a[i].y < 25) && ((x2 - a[i].x) * (x2 - a[i].x) + (y2 - a[i].y) * (y2 - a[i].y) < 2900 ))
                {
                    a[i].vy = - a[i].vy;
                    a[i].vx = - a[i].vx;
                    k = k + 1;
                }
            txSetColor (RGB (0, 0, 255), 2);
            txSelectFont ("Comic Sans MS", 50);
            sprintf   (st, "%d", k);
            txTextOut (10,  100, "Score: ");
            txTextOut (120, 100, st);
            if ((a[i].y == 580) && !(a[i].put))
                {
                    a[i].vx = 0;
                    a[i].vy = 0;
                    a[i].put = true;
                    count ++;
                }

        }
        if (count == n)
        {
            txSetColor   (RGB (255, 0, 0 ), 2);
            txSelectFont ("Arial", 50);
            txTextOut    (350, 300, "GAME OVER");
            txSleep      (100);
            break;
        }
        txSleep (20);
    }
    txEnd();
    return 0;
}

void PlayBall (int x, int y, COLORREF color)
{
    txSetColor (TX_BLACK, 1);
    txSetFillColor (color);
    txCircle (x, y, 20);
}

void Phisics (int *x, int *y, int *vx, int *vy)
{
    int ax = 0,   ay = 1,  dt = 1;
    *vx += ax * dt;
    *vy += ay * dt;
    *x += *vx * dt;
    *y += *vy * dt;
    if ( *x > 980)    { *vx = -*vx; *x = 960; }
    if ( *x < 20 )    { *vx = -*vx; *x = 40;  }
    if ( *y > 580)    { *vy = 0;    *y = 580; }
    if ( *y < 20 )    { *vy = -*vy; *y = 40;  }
}

void drawCar (int x, int y)
{
    txSetColor (TX_BLACK, 1);
    txSetFillColor (RGB (101, 67, 55));
    txRectangle (x - 50, y, x + 50, y + 10);
}

void MooveCar (int *xc, int yc)
{
    drawCar (*xc, yc);
    if (txGetAsyncKeyState (VK_LEFT))  *xc = *xc - 100;
    if (txGetAsyncKeyState (VK_RIGHT)) *xc = *xc + 100;
}

