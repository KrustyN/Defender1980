#include "Bomber.h"
#include "Explosion.h"
#include "Jugador.h"
#include "Disparo2.h"
#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <bits/stdc++.h>

Bomber::Bomber(int _x, int _y, Explosion _muerte, Jugador _direccion)
{
    x = _x;
    y = _y;
    muerte = _muerte;
    direccion = _direccion;
}

void Bomber::gotoxy(int x, int y)
{
    HANDLE hID;
    hID = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD cPos;
    cPos.X = x;
    cPos.Y = y;
    SetConsoleCursorPosition(hID, cPos);
}

void Bomber::radar()
{
    int rX = ((x/5)+79);
    int rY = ((y/5)-1);
    gotoxy(rX, rY);
    printf("%c",250);
}

void Bomber::borrarRadar()
{
    int rX = ((x/5)+79);
    int rY = ((y/5)-1);
    gotoxy(rX, rY);
    printf(" ");
}

void Bomber::dibujar()
{
    gotoxy(x-2, y);
    printf(" %c%c%c",91,254,93);
    gotoxy(x-2, y+1);
    printf("%c%c%c ",91,254,93);
    radar();
}

int Bomber::direccionX()
{
    return direccion.regresarX();
}

int Bomber::direccionY()
{
    return direccion.regresarY();
}

int Bomber::apuntar(int dirX, int dirY)
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

void Bomber::borrar()
{
    gotoxy(x-2, y);
    printf("     ");
    gotoxy(x-2, y+1);
    printf("     ");
    borrarRadar();
}

void Bomber::mover(int dirX, int dirY)
{
    borrar();
    dist = sqrt(pow(dirX - x, 2)+pow(dirY - y, 2));
    if(dirX > x && dist > 30)
    {
        x+=0.5;
    }
    if(dirY < y && dist > 15)
    {
        y-=0.5;
    }
    if(dirY > y && dist > 15)
    {
        y+=0.5;
    }
    if(dirX < x && dist > 35)
    {
        x-=0.5;
    }
    dibujar();
}

int Bomber::regresarX()
{
    return x;
}

int Bomber::regresarY()
{
    return y;
}

void Bomber::explotar()
{
    borrar();
    muerte.explotar(regresarX(), regresarY());
}
