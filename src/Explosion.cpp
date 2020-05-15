#include "Explosion.h"
#include "Jugador.h"
#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <conio.h>

Explosion::Explosion()
{

}

void Explosion::gotoxy(int x, int y)
{
    HANDLE hID;
    hID = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD cPos;
    cPos.X = x;
    cPos.Y = y;
    SetConsoleCursorPosition(hID, cPos);
}

void Explosion::explotar(int x, int y)
{
    gotoxy(x,y-2);
    printf("     ");
    gotoxy(x,y-1);
    printf("  *  ");
    gotoxy(x,y);
    printf(" *** ");
    gotoxy(x,y+1);
    printf("  *  ");
    gotoxy(x,y+2);
    printf("     ");
    Sleep(100);
    gotoxy(x,y-2);
    printf("     ");
    gotoxy(x,y-1);
    printf(" *** ");
    gotoxy(x,y);
    printf(" *** ");
    gotoxy(x,y+1);
    printf(" *** ");
    gotoxy(x,y+2);
    printf("     ");
    Sleep(200);
    gotoxy(x,y-2);
    printf("* * *");
    gotoxy(x,y-1);
    printf(" *** ");
    gotoxy(x,y);
    printf("*****");
    gotoxy(x,y+1);
    printf(" *** ");
    gotoxy(x,y+2);
    printf("* * *");
    Sleep(300);
    gotoxy(x,y-2);
    printf("* * *");
    gotoxy(x,y-1);
    printf(" * * ");
    gotoxy(x,y);
    printf("*   *");
    gotoxy(x,y+1);
    printf(" * * ");
    gotoxy(x,y+2);
    printf("* * *");
    Sleep(200);
    gotoxy(x,y-2);
    printf("* * *");
    gotoxy(x,y-1);
    printf("     ");
    gotoxy(x,y);
    printf("*   *");
    gotoxy(x,y+1);
    printf("     ");
    gotoxy(x,y+2);
    printf("* * *");
    Sleep(100);
    gotoxy(x,y-2);
    printf("     ");
    gotoxy(x,y-1);
    printf("     ");
    gotoxy(x,y);
    printf("     ");
    gotoxy(x,y+1);
    printf("     ");
    gotoxy(x,y+2);
    printf("     ");
}
