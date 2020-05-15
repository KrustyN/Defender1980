#include "Disparo.h"
#include <stdio.h>
#include <windows.h>
#include <conio.h>

Disparo::Disparo(int _x, int _y, bool _dir)
{
    x = _x;
    y = _y;
    dir = _dir;
}

void Disparo::gotoxy(int x, int y)
{
    HANDLE hID;
    hID = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD cPos;
    cPos.X = x;
    cPos.Y = y;
    SetConsoleCursorPosition(hID, cPos);
}

void Disparo::mover()
{
    gotoxy(x, y);
    printf("     ");
    if(dir)
        x+=3;
    else
        x-=3;
    gotoxy(x, y);
    printf("%c%c%c%c%c",205,205,205,205,205);
}

bool Disparo::limite()
{
    if(x >= 184 || x <= 7)
    {
        return true;
    }
    return false;
}

int Disparo::regresarX()
{
    return x;
}

int Disparo::regresarY()
{
    return y;
}
