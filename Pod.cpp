#include "Pod.h"
#include "Explosion.h"
#include "Jugador.h"
#include "Disparo2.h"
#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <conio.h>

Pod::Pod(int _x, int _y, Explosion _muerte, Jugador _direccion)
{
    x = _x;
    y = _y;
    muerte = _muerte;
    direccion = _direccion;
}

void Pod::gotoxy(int x, int y)
{
    HANDLE hID;
    hID = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD cPos;
    cPos.X = x;
    cPos.Y = y;
    SetConsoleCursorPosition(hID, cPos);
}

void Pod::radar()
{
    int rX = ((x/5)+79);
    int rY = ((y/5)-1);
    gotoxy(rX, rY);
    printf("%c",250);
}

void Pod::borrarRadar()
{
    int rX = ((x/5)+79);
    int rY = ((y/5)-1);
    gotoxy(rX, rY);
    printf(" ");
}

void Pod::dibujar()
{
    gotoxy(x-2, y);
    printf("%c%c%c",195,207,180);
    gotoxy(x-2, y+1);
    printf("%c%c%c",92,242,47);
    radar();
}

int Pod::direccionX()
{
    return direccion.regresarX();
}

int Pod::direccionY()
{
    return direccion.regresarY();
}

void Pod::borrar()
{
    gotoxy(x-2, y);
    printf("     ");
    gotoxy(x-2, y+1);
    printf("     ");
    borrarRadar();
}

void Pod::mover(int dirX, int dirY)
{
    borrar();
    if(dirX > x)
    {
        x+=0.3;
    }
    if(dirY < y)
    {
        y-=0.3;
    }
    if(dirY > y)
    {
        y+=0.3;
    }
    if(dirX < x)
    {
        x-=0.3;
    }
    dibujar();
}

int Pod::regresarX()
{
    return x;
}

int Pod::regresarY()
{
    return y;
}

void Pod::explotar()
{
    borrar();
    muerte.explotar(regresarX(), regresarY());
}


