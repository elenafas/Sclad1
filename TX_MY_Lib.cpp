//! @ file "TX_MY_Lib.h"
//! @ mainpage
//! @ selection
//! drawBob
//! drawCat
//! drawCat1
//! drawMirror
//! ClearSpace
//! drawMirBob
//! drawScreen
//! drawPortal
//! drawTitry
//! drawSpots
//! drawSpots1

#include "TXLib.h"

const COLORREF SUPER_YELLOW = RGB (255, 255, 0), SUPER_BRAWN = RGB (125, 125, 0);

void drawBob (double x, double y, double sizeX, double sizeY, bool lips, bool arm, int eyesL, int eyesR, int a);
void drawCat (int x, int y);
void drawCat1 (int x, int y, int k);
void drawMirror (int x, int y, int crack);
void ClearSpace();
void drawMirBob ();
void drawScreen (int sc);
void drawPortal (int x, int y, int a, int k, int r, int g, int b);
void drawTitry (int y);
void drawSpots (int x, int y);
void drawSpots1 (int x, int y);


//-----------------------------
//! @brief Рисует Объект Губка Боб
//! @param x, y - координаты начала рисования
//! @param sizeX, sizeY - масштабирование объекта
//! @param lips - рисование рта (0 - эллипс, 1 - линия)
//! @param arm - рисование рук (0 - руки вверх, 1 - руки вниз)
//! @param eyesL, eyesR - рисование левого/правого глаза (0 - круг, 1 - линия, 2 - эллипс)
//! @param a - рисование ног (0 - ноги ровно, 1 - поднята правая нога, 2 - поднята левая нога)
//! @ref txSetColor ()
//! @see txSetColor (), txSetFillColor(), txCircle ( , , ), txLine ( , , , ),  txEllipse ( , , , ), txRectangle ( , , , )
//! @endcode
void drawBob (double x, double y, double sizeX, double sizeY, bool lips, bool arm, int eyesL, int eyesR, int a)
{
    POINT body[4]  { {x, y}, {x + 150*sizeX, y}, {x + 135*sizeX, y + 200*sizeY}, {x + 15*sizeX, y + 200*sizeY} };
    POINT pants[4] { {x + 10*sizeX, y + 150*sizeY}, {x + 140*sizeX, y + 150*sizeY}, {x + 135*sizeX, y + 200*sizeY}, {x + 15*sizeX, y + 200*sizeY} };
    txSetColor (TX_BLACK);
    txSetFillColor (RGB (255, 255, 0));
    txPolygon (body, 4);
    txSetFillColor (RGB (101, 67, 33));
    txPolygon (pants, 4);
    if (eyesL == 0)
    {
        txSetFillColor (TX_WHITE);
        txCircle (x + 45*sizeX,  y + 45*sizeY, 30*sizeY/2);
        txSetFillColor (RGB (0, 83, 138));
        txCircle (x + 45*sizeX,  y + 45*sizeY, 15*sizeY/2);
        txSetFillColor (TX_BLACK);
        txCircle (x + 45*sizeX,  y + 45*sizeY, 10*sizeY/2);
    }
    else if (eyesL == 1)
    {
        txSetFillColor (TX_BLACK);
        txLine (x + 25*sizeX,  y + 45*sizeY, x + 65*sizeX,  y + 45*sizeY);
    }
    else
    {
        txSetFillColor (TX_WHITE);
        txEllipse (x + 30*sizeX,  y + 75*sizeY, x + 60*sizeX,  y + 15*sizeY);
        txSetFillColor (RGB (0, 83, 138));
        txEllipse (x + 35*sizeX,  y + 65*sizeY, x + 55*sizeX,  y + 25*sizeY);
        txSetFillColor (TX_BLACK);
        txEllipse (x + 40*sizeX,  y + 55*sizeY, x + 50*sizeX,  y + 35*sizeY);
    }
    if (eyesR == 0)
    {
        txSetFillColor (TX_WHITE);
        txCircle (x + 105*sizeX, y + 45*sizeY, 30*sizeY/2);
        txSetFillColor (RGB (0, 83, 138));
        txCircle (x + 105*sizeX,  y + 45*sizeY, 15*sizeY/2);
        txSetFillColor (TX_BLACK);
        txCircle (x + 105*sizeX,  y + 45*sizeY, 10*sizeY/2);
    }
    else if (eyesR == 1)
    {
        txSetFillColor (TX_BLACK);
        txLine (x + 85*sizeX,  y + 45*sizeY, x + 125*sizeX,  y + 45*sizeY);
    }
    else
    {
        txSetFillColor (TX_WHITE);
        txEllipse (x + 90*sizeX,  y + 75*sizeY, x + 120*sizeX,  y + 15*sizeY);
        txSetFillColor (RGB (0, 83, 138));
        txEllipse (x + 95*sizeX,  y + 65*sizeY, x + 115*sizeX,  y + 25*sizeY);
        txSetFillColor (TX_BLACK);
        txEllipse (x + 100*sizeX,  y + 55*sizeY, x + 110*sizeX,  y + 35*sizeY);
    }
    txSetFillColor (RGB (255, 255, 0));
    if (arm)
        {
        txRectangle (x + 12*sizeX,  y + 125*sizeY, x - 10*sizeX,  y + 75*sizeY);
        txRectangle (x + 137*sizeX, y + 125*sizeY, x + 159*sizeX, y + 75*sizeY);
        txCircle (x - 5*sizeX,   y + 73*sizeY, 12*sizeY);
        txCircle (x + 157*sizeX, y + 73*sizeY, 12*sizeY);
        }
    else
        {
        txRectangle (x + 12*sizeX,  y + 100*sizeY, x - 10*sizeX,  y + 175*sizeY);
        txRectangle (x + 137*sizeX, y + 100*sizeY, x + 159*sizeX, y + 175*sizeY);
        txCircle (x - 5*sizeX,   y + 178*sizeY, 12*sizeY);
        txCircle (x + 157*sizeX, y + 178*sizeY, 12*sizeY);
        }

    txSetColor (RGB (255, 0, 0));
    txSetFillColor (TX_RED);
    if ( lips ) {
        txSetColor(TX_RED, 3);
        txLine (x + 15*sizeX, y + 90*sizeY, x + 135*sizeX, y + 90*sizeY);
        }
    else {
        txSetColor(TX_RED, 1);
        txEllipse (x + 20*sizeX, y + 80*sizeY, x + 130*sizeX, y + 100*sizeY);
        }
        txSetColor (TX_BLACK);
        txSetFillColor (RGB (255, 255, 0));
    if (a == 0 or a == 40)
    {
        txRectangle (x + 30*sizeX, y + 200*sizeY, x + 50*sizeX,  y + 250*sizeY);
        txRectangle (x + 90*sizeX, y + 200*sizeY, x + 110*sizeX, y + 250*sizeY);
        txSetFillColor (TX_BLACK);
        txRectangle (x + 52*sizeX, y + 250*sizeY, x + 22*sizeX,  y + 235*sizeY);
        txRectangle (x + 88*sizeX, y + 250*sizeY, x + 118*sizeX, y + 235*sizeY);
    }
    else if (a % 2 == 1)
    {
        txRectangle (x + 30*sizeX, y + 200*sizeY, x + 50*sizeX,  y + 250*sizeY);
        txRectangle (x + 90*sizeX, y + 200*sizeY, x + 110*sizeX, y + 225*sizeY);
        txSetFillColor (TX_BLACK);
        txRectangle (x + 52*sizeX, y + 250*sizeY, x + 22*sizeX,  y + 235*sizeY);
        txRectangle (x + 88*sizeX, y + 225*sizeY, x + 118*sizeX, y + 210*sizeY);
    }
    else
    {
        txRectangle (x + 30*sizeX, y + 200*sizeY, x + 50*sizeX,  y + 225*sizeY);
        txRectangle (x + 90*sizeX, y + 200*sizeY, x + 110*sizeX, y + 250*sizeY);
        txSetFillColor (TX_BLACK);
        txRectangle (x + 52*sizeX, y + 225*sizeY, x + 22*sizeX,  y + 210*sizeY);
        txRectangle (x + 88*sizeX, y + 250*sizeY, x + 118*sizeX, y + 235*sizeY);
    }

    }

//-----------------------------
//! @brief Рисует движение Кота
//! @param x, y - координаты начала рисования
//! @endcode
void drawCat (int x, int y)
{
    txSetColor (TX_BLACK, 1);
    while (x >= 100)
    {
        ClearSpace();
        drawCat1 (x, y, 3);
        drawSpots (x, y);
        x = x - 5;
        txSleep (30);
    }
    txSetColor (RGB (0, 0, 255), 2);
    txSelectFont ("Arial", 20, 0, FW_BOLD);
    txDrawText	(300, y, 800, y + 100, "Вот твои пятна!!!");
    txSleep (500);
    drawCat1 (100, 300, 0);
    txSleep (500);
}

//-----------------------------
//! @brief Рисует Объект Зеркало
//! @param x, y - координаты начала рисования
//! @param crack - 0 - зеркало целое, 1 - появление трещины, 2 - расколовшееся зеркало
//! @endcode
void drawMirror (int x, int y, int crack)
{
    int x1, x2, y1, y2;
    txSetFillColor(TX_WHITE);

    if (crack == 2)
    {
        x1 = x - 50;
        y1 = y + 50;
        x2 = x + 50;
        y2 = y - 50;
    }
    else if (crack == 1)
    {
        x1 = x ;
        y1 = y ;
        x2 = x ;
        y2 = y ;
    }

    POINT rama0[4]  { {x, y}, {x + 300, y - 50}, {x + 300, y + 400}, {x, y + 450} };
    POINT rama1[7] { {x1, y1}, {x1 + 125, y1 - 25}, {x1 + 175, y1 + 100}, {x1 + 100, y1 + 225}, {x1 + 175, y1 + 350}, {x1 + 150, y1 + 425}, {x1, y1 + 450} };
    POINT rama2[7] { {x2 + 300, y2 - 50}, {x2 + 125, y2 - 25}, {x2 + 175, y2 + 100}, {x2 + 100, y2 + 225}, {x2 + 175, y2 + 350}, {x2 + 150, y2 + 425}, {x2 + 300, y2 + 400} };
    txSetColor (TX_BLUE, 6);
    if (crack == 0)
    {
      txPolygon (rama0, 4);
    }
    else if (crack == 1)
    {
        txPolygon (rama1, 7);
        txPolygon (rama2, 7);
    }
    else if (crack == 2)
    {
        txPolygon (rama1, 7);
        txPolygon (rama2, 7);
    }
    else
    {
        txLine (x + 125, y - 25, x + 175, y + 100);
        txLine (x + 175, y + 100, x + 100, y + 225);
        txLine (x + 100, y + 225, x + 175, y + 350);
        txLine (x + 175, y + 350, x + 150, y + 425);
    }
 }

//-----------------------------
//! @brief Очищает холст
//! @endcode
void ClearSpace()
{
    txSetFillColor(TX_WHITE);
    txClear();
}

//-----------------------------
//! @brief Рисует Портал из 3 фигур: квадрат, круг, 8-угольник
//! @param x, y - координаты начала рисования
//! @param r, g, b - генерация интенсивности основных цветов (красный, зелёный, синий) для заливки
//! @param k - количество повторений рисования фигур
//! @param a - сторона большего квадрата
//! @endcode
void drawPortal (int x, int y, int a, int k, int r, int g, int b)
{
    int i;
    txSetColor (RGB (0, 0, 0), 1);
    srand (time (0));
    txClear();
    for (i = 1; i<= k; i++)
    {
        r = rand() % 256 + 1;
        g = rand() % 256 + 1;
        b = rand() % 256 + 1;
        POINT j8 [8] {{x - a, y},{x - int (0.7*a), y - int(0.7*a)},{x, y - a},{x + int (0.7*a), y - int (0.7*a)},{x + a, y},{x + int (0.7*a), y + int (0.7*a)},{x, y + a}, {x - int (0.7*a), y + int (0.7*a)}};
        txSetFillColor (RGB (r, g, b));
        txRectangle (x-a, y-a, x+a, y+a);
        txSleep (100);
        r = rand() % 256 + 1;
        g = rand() % 256 + 1;
        b = rand() % 256 + 1;
        txSetFillColor (RGB (r, g, b));
        txCircle (x, y, a);
        txSleep (100);
        r = rand() % 256 + 1;
        g = rand() % 256 + 1;
        b = rand() % 256 + 1;
        txSetFillColor (RGB (r, g, b));
        txPolygon (j8, 8);
        txSleep (100);
        a = int(a/1.44);
    }
}

//-----------------------------
//! @brief Сцена общения Губки Боба с зеркалом
//! @endcode
void drawMirBob ()
{
    ClearSpace();
    drawMirror (100, 100, 0);
    drawBob (450, 250, 1.1, 1.1, 1, 0, 0, 0, 0);
    txSelectFont ("Arial", 30);
    txTextOut (650, 200,  "Где мои пятна???");
    drawBob (150, 250, 1, 1, 1, 0, 0, 0, 0);
    txSleep (1000);
    ClearSpace();
    drawMirror (100, 100, 0);
    drawBob (450, 250, 1.1, 1.1, 0, 1, 2, 2, 0);
    txSelectFont ("Arial", 30);
    txTextOut (650, 200,  "Где мои пятна???");
    drawBob (150, 250, 1, 1, 0, 1, 2, 2, 0);
    txSleep (1000);
    drawBob (450, 250, 1.1, 1.1, 0, 1, 2, 2, 0);
    drawBob (150, 250, 1, 1, 0, 1, 2, 2, 0);
    drawMirror (100, 100, 3);
    txSleep (1000);
    ClearSpace();
    drawMirror (100, 100, 2);
    drawBob (450, 250, 1.1, 1.1, 0, 1, 2, 2, 0);
    txSleep (1000);
    ClearSpace();
}

//-----------------------------
//! @brief Заствка смены сцены
//! @param sc - номер сцены
//! @endcode
void drawScreen (int sc)
{   char st[11];
    txClear();
    txSetColor (RGB (0, 0, 255), 2);
    txSelectFont ("Comic Sans MS", 70);
    txTextOut (350, 300, "SCENA");
    sprintf (st, "%d", sc);
    txTextOut (550, 300, st);
    txSleep (2000);
 }

//-----------------------------
//! @brief Начальные титры
//! @param y - начало появления текста по вертикали
//! @endcode
void drawTitry (int y)
{
    txClear();
    txSetColor (RGB (0, 0, 255), 2);
    while (y > -100)
    {
        txClear ();
        ClearSpace();
        txSelectFont ("Arial", 40, 0, FW_BOLD);
        txDrawText	(200, y, 700, y + 100, "Это мультик про ПЯТНА");
        y = y - 10;
        txSleep (30);
    }
    }

//-----------------------------
//! @brief Рисует Объект Кот
//! @param x, y - координаты начала рисования
//! @param k - амплитуда движения лап и хвоста
//! @endcode
void drawCat1 (int x, int y, int k)
{
    txSetColor (RGB (101, 67, 33));
    txSetFillColor (RGB (101, 67, 33));
    txLine (x + 50,  y + 100, x + 20,  y);
    txLine (x + 20,  y,       x + 100, y + 50);
    txLine (x + 100, y + 50,  x + 50,  y + 100);
    txLine (x + 200, y + 50,  x + 280, y);
    txLine (x + 280, y,       x + 250, y + 120);
    txLine (x + 250, y + 120, x + 200, y + 50);
    txFloodFill (x + 50,  y + 50);
    txFloodFill (x + 250, y + 50);
    txSetFillColor (RGB (101, 67, 33));
    k = k * (x % 2);
    txEllipse (x + 120, y + 300 - k, x + 140, y + 260 - k);
    txEllipse (x + 145, y + 260 + k, x + 165, y + 300 + k);
    txEllipse (x + 260, y + 300 + k, x + 240, y + 260 + k);
    txEllipse (x + 235, y + 260 - k, x + 215, y + 300 - k);
    txLine (x + 250, y + 240, x + 250, y + 260);
    txLine (x + 250, y + 260, x + 290, y + 240 - 2*k);
    txLine (x + 290, y + 240 - 2*k, x + 250, y + 240);
    txFloodFill (x + 260,  y + 245);
    txRectangle (x + 120, y + 180, x + 150, y + 250);
    txEllipse   (x + 40,  y + 200, x + 280, y + 20);
    txEllipse   (x + 120, y + 220, x + 260, y + 280);
    txSetFillColor (RGB (0, 255, 255));
    txEllipse (x + 50,  y + 160, x + 130, y + 90);
    txEllipse (x + 190, y + 160, x + 270, y + 90);
    txSetFillColor (TX_BLACK);
    txCircle (x + 90,  y + 130, 10);
    txCircle (x + 230, y + 130, 10);
    txCircle (x + 160,  y + 150, 15);
}

//-----------------------------
//! @brief Рисует Пятна
//! @param x, y - координаты начала рисования
//! @endcode
void drawSpots (int x, int y)
{
    txSetFillColor (SUPER_BRAWN);
    txCircle (x + 150,  y + 250, 10);
    txCircle (x + 220,  y + 240, 10);
    txCircle (x + 190,  y + 260, 10);
}

//-----------------------------
//! @brief Рисует движение Пятен
//! @param x, y - координаты начала рисования
//! @endcode
 void drawSpots1 (int x, int y)
{
    int t = 0;
    while (t <= 17)
    {
        txClear ();
        ClearSpace();
        drawSpots (x, y);
        x = x + 30;
        y = y - 10;
        t += 1;
        txSleep (50);
    }
}

