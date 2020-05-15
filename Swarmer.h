#ifndef SWARMER_H
#define SWARMER_H
#include "Explosion.h"
#include "Jugador.h"
#include "Disparo2.h"


class Swarmer
{
    float x;
    float y;
    Explosion muerte;
    Jugador direccion;
    int dir;
    public:
        Swarmer(int _x, int _y, Explosion _muerte, Jugador _direccion);
        void gotoxy(int, int);
        void radar();
        void borrarRadar();
        void dibujar();
        int direccionX();
        int direccionY();
        void borrar();
        void mover(int, int);
        int regresarX();
        int regresarY();
        void explotar();
};

#endif // SWARMER_H
