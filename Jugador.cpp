#include "Jugador.h"
#include "Explosion.h"
#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <conio.h>

Jugador::Jugador()
{ }

Jugador::Jugador(int _x, int _y, bool _dir, int _vida, Explosion _muerte)
{
    x = _x;
    y = _y;
    dir = _dir;
    vida = _vida;
    muerte = _muerte;
}

void Jugador::gotoxy(int x, int y)
{
    HANDLE hID;
    hID = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD cPos;
    cPos.X = x;
    cPos.Y = y;
    SetConsoleCursorPosition(hID, cPos);
}

void Jugador::radar()
{
    int rX = ((x/5)+79);
    int rY = ((y/5)-1);
    gotoxy(rX, rY);
    printf("%c",250);
}

void Jugador::borrarRadar()
{
    int rX = ((x/5)+79);
    int rY = ((y/5)-1);
    gotoxy(rX, rY);
    printf(" ");
}

void Jugador::dibujar(bool dir)
{
    if(dir)
    {
        gotoxy(x, y);
        printf("%c%c%c",91,92,242);
        gotoxy(x, y+1);
        printf("%c%c%c%c%c",200,202,202,202,248);
    }
    else
    {
        gotoxy(x, y);
        printf("  %c%c%c",242,47,93);
        gotoxy(x, y+1);
        printf("%c%c%c%c%c",248,202,202,202,188);
    }
    radar();
}

void Jugador::borrar()
{
    gotoxy(x, y);
    printf("     ");
    gotoxy(x, y+1);
    printf("     ");
    borrarRadar();
}

void Jugador::impulso()
{
    if(dir)
    {
        gotoxy(x-3, y);
        printf("%c%c%c",250,240,174);
    }
    else
    {
        gotoxy(x+5, y);
        printf("%c%c%c",175,240,250);
    }
}

void Jugador::borrarImpulso()
{
    if(dir)
    {
        gotoxy(x-3, y);
        printf("   ");
    }
    else
    {
        gotoxy(x+5, y);
        printf("   ");
    }
}

void Jugador::mover()
{
    if(kbhit())
        {
            borrar();
            borrarImpulso();
            if(GetAsyncKeyState(0x57) && y > 9)
                y--;
            if(GetAsyncKeyState(0x53) && y < 32)
                y++;
            if(GetAsyncKeyState(0x44) && x < 187)
            {
                x++;
                dir = true;
                impulso();
            }
            if(GetAsyncKeyState(0x41) && x > 3)
            {
                x--;
                dir = false;
                impulso();
            }
            dibujar(dir);
            vidasRestantes();
        }
}

bool Jugador::regresarDir()
{
    return dir;
}

void Jugador::vidasRestantes()
{
    gotoxy(3, 1);
    printf("VIDAS:");
    gotoxy(10, 1);
    printf("         ");
    for(int i = 0; i < vida*3; i=i+3)
    {
        gotoxy(i+10, 1);
        printf(" %c%c",200,205);
    }
}

int Jugador::regresarX()
{
    return x;
}

int Jugador::regresarY()
{
    return y;
}

void Jugador::explotar()
{
    borrar();
    muerte.explotar(regresarX(), regresarY());
    vida--;
    vidasRestantes();
}
