#include "Swarmer.h"
#include "Explosion.h"
#include "Jugador.h"
#include "Disparo2.h"
#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <conio.h>

Swarmer::Swarmer(int _x, int _y, Explosion _muerte, Jugador _direccion)
{
    x = _x;
    y = _y;
    muerte = _muerte;
    direccion = _direccion;
}

void Swarmer::gotoxy(int x, int y)
{
    HANDLE hID;
    hID = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD cPos;
    cPos.X = x;
    cPos.Y = y;
    SetConsoleCursorPosition(hID, cPos);
}

void Swarmer::radar()
{
    int rX = ((x/5)+79);
    int rY = ((y/5)-1);
    gotoxy(rX, rY);
    printf("%c",250);
}

void Swarmer::borrarRadar()
{
    int rX = ((x/5)+79);
    int rY = ((y/5)-1);
    gotoxy(rX, rY);
    printf(" ");
}

void Swarmer::dibujar()
{
    gotoxy(x-2, y);
    printf("%c",207);
    gotoxy(x-2, y+1);
    printf("%c",238);
    radar();
}

int Swarmer::direccionX()
{
    return direccion.regresarX();
}

int Swarmer::direccionY()
{
    return direccion.regresarY();
}

void Swarmer::borrar()
{
    gotoxy(x-2, y);
    printf("     ");
    gotoxy(x-2, y+1);
    printf("     ");
    borrarRadar();
}

void Swarmer::mover(int dirX, int dirY)
{
    borrar();
    if(dirX > x)
    {
        x+=0.1;
    }
    if(dirY < y)
    {
        y-=0.1;
    }
    if(dirY > y)
    {
        y+=0.1;
    }
    if(dirX < x)
    {
        x-=0.1;
    }
    dibujar();
}

int Swarmer::regresarX()
{
    return x;
}

int Swarmer::regresarY()
{
    return y;
}

void Swarmer::explotar()
{
    borrar();
    muerte.explotar(regresarX(), regresarY());
}
