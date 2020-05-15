#ifndef JUGADOR_H
#define JUGADOR_H
#include "Explosion.h"


class Jugador
{
    int x;
    int y;
    bool dir;
    int vida;
    Explosion muerte;
    public:
        Jugador();
        Jugador(int _x, int _y, bool, int _vida, Explosion _muerte);
        void gotoxy(int, int);
        void radar();
        void borrarRadar();
        void dibujar(bool);
        void impulso();
        void borrarImpulso();
        void mover();
        void borrar();
        bool regresarDir();
        void vidasRestantes();
        int regresarX();
        int regresarY();
        void explotar();
};

#endif // JUGADOR_H

