#ifndef BAITER_H
#define BAITER_H
#include "Explosion.h"
#include "Jugador.h"
#include "Disparo2.h"


class Baiter
{
    float x;
    float y;
    Explosion muerte;
    Jugador direccion;
    int dir;
    float dist;
    public:
        Baiter(int _x, int _y, Explosion _muerte, Jugador _direccion);
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

#endif // BAITER_H
