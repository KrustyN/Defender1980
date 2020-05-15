#include "Mutant.h"
#include "Explosion.h"
#include "Jugador.h"
#include "Disparo2.h"
#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <bits/stdc++.h>

Mutant::Mutant(int _x, int _y, Explosion _muerte, Jugador _direccion)
{
    x = _x;
    y = _y;
    muerte = _muerte;
    direccion = _direccion;
}

void Mutant::gotoxy(int x, int y)
{
    HANDLE hID;
    hID = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD cPos;
    cPos.X = x;
    cPos.Y = y;
    SetConsoleCursorPosition(hID, cPos);
}

void Mutant::radar()
{
    int rX = ((x/5)+79);
    int rY = ((y/5)-1);
    gotoxy(rX, rY);
    printf("%c",250);
}

void Mutant::borrarRadar()
{
    int rX = ((x/5)+79);
    int rY = ((y/5)-1);
    gotoxy(rX, rY);
    printf(" ");
}

void Mutant::dibujar()
{
    gotoxy(x-2, y);
    printf("%c%c%c",174,173,175);
    gotoxy(x-2, y+1);
    printf("%c%c%c",47,179,92);
    radar();
}

int Mutant::direccionX()
{
    return direccion.regresarX();
}

int Mutant::direccionY()
{
    return direccion.regresarY();
}

int Mutant::apuntar(int dirX, int dirY)
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

void Mutant::borrar()
{
    gotoxy(x-2, y);
    printf("     ");
    gotoxy(x-2, y+1);
    printf("     ");
    borrarRadar();
}

void Mutant::mover(int dirX, int dirY)
{
    borrar();
    dist = sqrt(pow(dirX - x, 2)+pow(dirY - y, 2));
    if(dirX > x && dist > 35)
    {
        x+=0.9;
    }
    if(dirY < y && dist > 20)
    {
        y-=0.9;
    }
    if(dirY > y && dist > 20)
    {
        y+=0.9;
    }
    if(dirX < x && dist > 40)
    {
        x-=0.9;
    }
    dibujar();
}

int Mutant::regresarX()
{
    return x;
}

int Mutant::regresarY()
{
    return y;
}

void Mutant::explotar()
{
    borrar();
    muerte.explotar(regresarX(), regresarY());
}
