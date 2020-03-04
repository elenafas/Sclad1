#include "TXLib.h"
typedef double Sorrt (int *data, int lenD, int *countObm);
struct  My_button
{
    int x;
    int y;
    char st[20];
    COLORREF color;
    void DrawButton();
};

int sizeX = 1000;

void Screen ();
int ControlButton();
void ClearScreen (int x1);
void TextScreen ();
double Bubble     (int *data, int lenD, int *countObm);
double Insert     (int *data, int lenD, int *countObm);
double Selection  (int *data, int lenD, int *countObm);
double Gnome      (int *data, int lenD, int *countObm);
void DrawGraphic (int x, int y, COLORREF color, int x0);
void PrintGraph (Sorrt* func, COLORREF color);
void FillArray (int *data, int lenD);

int main ()
{
    srand(time(0));
    Screen ();
    My_button Butt[5] = {{0,  0, "Bubble",    RGB (255, 0  , 0  )},
                        {200, 0, "Insert",    RGB (200, 200, 0  )},
                        {400, 0, "Selection", RGB (0  , 255, 0  )},
                        {600, 0, "Gnome",     RGB (255, 0  , 255)},
                        {800, 0, "Clear",     RGB (0  , 0  , 0 )}};
    for (int i = 0; i < 5; i++)
         { Butt[i].DrawButton(); }

    while (!txGetAsyncKeyState (VK_ESCAPE))
    {
        int NomberButton = ControlButton();
        switch(NomberButton)
        {
        case 1 : {PrintGraph (&Bubble,    RGB (255, 0,   0)); break;}
        case 2 : {PrintGraph (&Insert,    RGB (200, 200, 0)); break;}
        case 3 : {PrintGraph (&Selection, RGB (0  , 255, 0)); break;}
        case 4 : {PrintGraph (&Gnome,     RGB (255, 0, 255)); break;}
        case 5 : {ClearScreen (0); ClearScreen (500);  break;}
        }
    }
   return 0;
}

void Screen ()
{
    txCreateWindow (sizeX, 700);
    txSetFillColor(TX_LIGHTBLUE);
    txRectangle (0, 0, sizeX, 69);
    ClearScreen (0);
    ClearScreen (500);
    TextScreen ();
}

void ClearScreen (int x1)
{
    char sf[8];
    txSetColor(TX_BLACK);
    txSetFillColor(TX_BLACK);
    txRectangle (x1, 120, x1 + sizeX / 2, 700);
    txSetColor(TX_WHITE, 2);
    txLine (x1 + 20,  660, x1 + 498, 660);
    txLine (x1 + 20,  660, x1 + 20,  100);
    txLine (x1 + 498, 660, x1 + 493, 665);
    txLine (x1 + 498, 660, x1 + 493, 655);
    txLine (x1 + 20,  100, x1 +  15, 105);
    txLine (x1 + 20,  100, x1 +  25, 105);
    txSelectFont ("Comic Sans MS", 15);
     for (int i = 1; i < 8; i++)
        {
        txLine (x1 + 15, 660 - i * 75, x1 +  25, 660 -  i * 75 );
        int ky = 50000 * i;
        sprintf   (sf, "%d", ky);
        txTextOut (x1 + 28,  653 -  i * 75, sf);
        }
    txTextOut (x1 + 175, 683, "Количество элементов в массиве");
    for (int i = 1; i < 11; i++)
        {
        txLine (i * 47 + x1 + 15, 662, i * 47 + x1 +  15, 658 );
        int kx = 100 * i;
        sprintf   (sf, "%d", kx);
        txTextOut (i * 47 + x1 + 3, 660, sf);
        }
}

void My_button :: DrawButton ()
{
    txSetColor (TX_WHITE, 2);
    txSetFillColor (color);
    txRectangle (x + 10, y + 10 , x + 190, y + 60);
    txSelectFont ("Comic Sans MS", 30);
    txTextOut (x + 55, y + 20, st);
}

int ControlButton()
{
    if (txMouseButtons() == 1 && txMouseX() >  10 && txMouseX() < 190 && txMouseY() > 0 && txMouseY() < 50)
        {return 1;}
    if (txMouseButtons() == 1 && txMouseX() > 210 && txMouseX() < 390 && txMouseY() > 0 && txMouseY() < 50)
        {return 2;}
    if (txMouseButtons() == 1 && txMouseX() > 410 && txMouseX() < 590 && txMouseY() > 0 && txMouseY() < 50)
        {return 3;}
    if (txMouseButtons() == 1 && txMouseX() > 610 && txMouseX() < 790 && txMouseY() > 0 && txMouseY() < 50)
        {return 4;}
    if (txMouseButtons() == 1 && txMouseX() > 810 && txMouseX() < 990 && txMouseY() > 0 && txMouseY() < 50)
        {return 5;}
    }

void PrintGraph (Sorrt* func, COLORREF color)
{
    int lenD = 1;
    while (lenD < 996)
    {
        int data [lenD];
        FillArray (data, lenD);
        int countObm = 0;
        int countIt = (*func) (data, lenD, &countObm);
        DrawGraphic (lenD, countObm, color, 20  );
        DrawGraphic (lenD, countIt,  color, 520);
        lenD = lenD + 4 ;
        txSleep(10);
     }
}

void DrawGraphic (int x, int y, COLORREF color, int x0)
{
    txSetColor (color);
    txSetFillColor (color);
    if (660 - 0.0015 * y > 125)
        {txCircle (x * 0.47 + x0, 660 - 0.0015 * y, 2);}
}

void FillArray (int *data, int lenD)
{
    for (int i = 0; i < lenD; i++)
        {
        data[i] = rand() % 100;
        }
}

double Bubble (int *data, int lenD,  int *countObm)
{
    int tmp = 0;
    int k = 0;
    for(int i = 0; i < lenD; i++)
    {
        for(int j = (lenD - 1); j >= (i + 1); j--)
        {
            if(data[j] < data[j-1])
            {
                tmp = data[j];
                data[j] = data[j - 1];
                data[j - 1] = tmp;
                *countObm = *countObm + 1;
            }
            k++;
        }
    }
    return k;
}

double Insert (int *data, int lenD, int *countObm)
{
  int tmp = 0;
  int k = 0;
  int i = 0;
  int p = 0;
  for(int j = 1; j < lenD; j++)
  {
      k++;
      tmp = data[j];
      i = j - 1;
      while(i >= 0 && data[i] > tmp)
        {
          data[i + 1] = data[i];
          i = i - 1;
          data[i + 1] = tmp;
          *countObm = *countObm + 1;
          k++;
          }
  }
    return k;
}

double Selection (int *data, int lenD, int *countObm)
{
  int j = 0;
  int tmp = 0;
  int k = 0;
  for(int i = 0; i < lenD; i++)
  {
    j = i;
    for(int m = i; m < lenD; m++)
    {
      if(data[j] > data[m])
      {
        j = m;
      }
      k++;
    }
    if (i!=j)
    {tmp = data[i];
    data[i] = data[j];
    data[j] = tmp;
    *countObm = *countObm + 1;}
  }
  return k;
}

double Gnome (int *data, int lenD, int *countObm)
{
    int i = 1;
    int tmp = 0;
    int k = 0;
    while (i < lenD)
    {
    k++;
    if (i == 0 || data[i-1] <= data[i])
        {i++;}
    else
        {
        tmp = data[i];
        data[i] = data[i-1];
        data[i-1] = tmp;
        i--;
        *countObm = *countObm + 1;
        }
        }
    return k;

}

void TextScreen ()
{
     txSelectFont ("Comic Sans MS", 15);
     txTextOut (15,  80, "Количество обменов");
     txTextOut (515, 80, "Количество сравнений");
}
