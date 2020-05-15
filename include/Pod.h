#ifndef POD_H
#define POD_H
#include "Explosion.h"
#include "Jugador.h"
#include "Disparo2.h"


class Pod
{
    float x;
    float y;
    Explosion muerte;
    Jugador direccion;
    int dir;
    public:
        Pod(int _x, int _y, Explosion _muerte, Jugador _direccion);
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

#endif // POD_H
