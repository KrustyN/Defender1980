#include "Lander.h"
#include "Explosion.h"
#include "Jugador.h"
#include "Disparo2.h"
#include "Astronauta.h"
#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <bits/stdc++.h>

Lander::Lander(int _x, int _y, Explosion _muerte, Jugador _direccion, Astronauta _objetivo)
{
    x = _x;
    y = _y;
    muerte = _muerte;
    direccion = _direccion;
    objetivo = _objetivo;
}

void Lander::gotoxy(int x, int y)
{
    HANDLE hID;
    hID = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD cPos;
    cPos.X = x;
    cPos.Y = y;
    SetConsoleCursorPosition(hID, cPos);
}

void Lander::radar()
{
    int rX = ((x/5)+79);
    int rY = ((y/5)-1);
    gotoxy(rX, rY);
    printf("%c",250);
}

void Lander::borrarRadar()
{
    int rX = ((x/5)+79);
    int rY = ((y/5)-1);
    gotoxy(rX, rY);
    printf(" ");
}

void Lander::dibujar()
{
    gotoxy(x-2, y);
    printf("%c%c%c",174,207,175);
    gotoxy(x-2, y+1);
    printf("%c%c%c",47,179,92);
    radar();
}

int Lander::direccionX()
{
    return direccion.regresarX();
}

int Lander::direccionY()
{
    return direccion.regresarY();
}

int Lander::apuntar(int dirX, int dirY)
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

void Lander::borrar()
{
    gotoxy(x-2, y);
    printf("     ");
    gotoxy(x-2, y+1);
    printf("     ");
    borrarRadar();
}

void Lander::mover(int dirX, int dirY)
{
    borrar();
    dist = sqrt(pow(dirX - x, 2)+pow(dirY - y, 2));
    if(dirX > x && dist > 35)
    {
        x+=0.25;
    }
    if(dirY < y && dist > 20)
    {
        y-=0.25;
    }
    if(dirY > y && dist > 20)
    {
        y+=0.25;
    }
    if(dirX < x && dist > 40)
    {
        x-=0.25;
    }
    dibujar();
}

int Lander::regresarX()
{
    return x;
}

int Lander::regresarY()
{
    return y;
}

void Lander::explotar()
{
    borrar();
    muerte.explotar(regresarX(), regresarY());
}
