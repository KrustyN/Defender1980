#include "Baiter.h"
#include "Explosion.h"
#include "Jugador.h"
#include "Disparo2.h"
#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <bits/stdc++.h>

Baiter::Baiter(int _x, int _y, Explosion _muerte, Jugador _direccion)
{
    x = _x;
    y = _y;
    muerte = _muerte;
    direccion = _direccion;
}

void Baiter::gotoxy(int x, int y)
{
    HANDLE hID;
    hID = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD cPos;
    cPos.X = x;
    cPos.Y = y;
    SetConsoleCursorPosition(hID, cPos);
}

void Baiter::radar()
{
    int rX = ((x/5)+79);
    int rY = ((y/5)-1);
    gotoxy(rX, rY);
    printf("%c",250);
}

void Baiter::borrarRadar()
{
    int rX = ((x/5)+79);
    int rY = ((y/5)-1);
    gotoxy(rX, rY);
    printf(" ");
}

void Baiter::dibujar()
{
    gotoxy(x-2, y);
    printf(" %c%c%c ",242,242,242);
    gotoxy(x-2, y+1);
    printf("%c%c%c%c%c",47,61,61,61,92);
    radar();
}

int Baiter::direccionX()
{
    return direccion.regresarX();
}

int Baiter::direccionY()
{
    return direccion.regresarY();
}

int Baiter::apuntar(int dirX, int dirY)
{
    if((dirX > x-4 && dirX < x+4) && dirY < y-5)
    {
        dir = 0;
    }
    else if(dirX >= x+4 && dirY < y-5)
    {
        dir = 1;
    }
    else if(dirX > x+10 && (dirY > y-5 && dirY < y+5))
    {
        dir = 2;
    }
    else if(dirX >= x+10 && dirY > y)
    {
        dir = 3;
    }
    if((dirX > x-10 && dirX < x+10) && dirY > y)
    {
        dir = 4;
    }
    else if(dirX <= x-10 && dirY > y)
    {
        dir = 5;
    }
    else if(dirX < x-10 && (dirY > y-5 && dirY < y+5))
    {
        dir = 6;
    }
    else if(dirX <= x-10 && dirY < y)
    {
        dir = 7;
    }
    return dir;
}

void Baiter::borrar()
{
    gotoxy(x-2, y);
    printf("     ");
    gotoxy(x-2, y+1);
    printf("     ");
    borrarRadar();
}

void Baiter::mover(int dirX, int dirY)
{
    borrar();
    dist = sqrt(pow(dirX - x, 2)+pow(dirY - y, 2));
    if(dirX > x && dist > 20)
    {
        x+=0.75;
    }
    if(dirY < y && dist > 10)
    {
        y-=0.75;
    }
    if(dirY > y && dist > 10)
    {
        y+=0.75;
    }
    if(dirX < x && dist > 25)
    {
        x-=0.75;
    }
    dibujar();
}

int Baiter::regresarX()
{
    return x;
}

int Baiter::regresarY()
{
    return y;
}

void Baiter::explotar()
{
    borrar();
    muerte.explotar(regresarX(), regresarY());
}
