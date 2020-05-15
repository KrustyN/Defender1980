#ifndef LANDER_H
#define LANDER_H
#include "Explosion.h"
#include "Jugador.h"
#include "Disparo2.h"
#include "Astronauta.h"


class Lander
{
    float x;
    float y;
    Explosion muerte;
    Jugador direccion;
    Astronauta objetivo;
    int dir;
    float dist;
    public:
        Lander(int _x, int _y, Explosion _muerte, Jugador _direccion, Astronauta _objetivo);
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

#endif // LANDER_H

