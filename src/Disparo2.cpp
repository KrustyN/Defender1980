#include "Disparo2.h"
#include <stdio.h>
#include <windows.h>
#include <conio.h>

Disparo2::Disparo2(int _x, int _y, int _dir)
{
    x = _x;
    y = _y;
    dir = _dir;
}

void Disparo2::gotoxy(int x, int y)
{
    HANDLE hID;
    hID = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD cPos;
    cPos.X = x;
    cPos.Y = y;
    SetConsoleCursorPosition(hID, cPos);
}

void Disparo2::mover()
{
    gotoxy(x,y);
    printf(" ");
    switch(dir)
    {
        case 0: y--; break;
        case 1: y--; x++; break;
        case 2: x++; break;
        case 3: y++; x++; break;
        case 4: y++; break;
        case 5: y++; x--; break;
        case 6: x--; break;
        case 7: y--; x--; break;
    }
    gotoxy(x,y);
    if(st)
    {
        st = false;
        printf("x");
    }
    else
    {
        st = true;
        printf("+");
    }
}

bool Disparo2::limite()
{
    if(x >= 184 || x <= 7 || y >= 32 || y <= 7)
    {
        return true;
    }
    return false;
}

int Disparo2::regresarX()
{
    return x;
}

int Disparo2::regresarY()
{
    return y;
}
