#ifndef MUTANT_H
#define MUTANT_H
#include "Explosion.h"
#include "Jugador.h"
#include "Disparo2.h"


class Mutant
{
    float x;
    float y;
    Explosion muerte;
    Jugador direccion;
    int dir;
    float dist;
    public:
        Mutant(int _x, int _y, Explosion _muerte, Jugador _direccion);
        void gotoxy(int, int);
        void radar();
        void borrarRadar();
        void dibujar();
        int direccionX();
        int direccionY();
        int apuntar(int, int);
        void borrar();
        void mover(int, int);
        int regresarX();
        int regresarY();
        void explotar();
};

#endif // MUTANT_H


