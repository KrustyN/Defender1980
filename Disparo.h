#ifndef DISPARO_H
#define DISPARO_H


class Disparo
{
    int x;
    int y;
    bool dir;
    public:
        Disparo(int, int, bool);
        void gotoxy(int, int);
        void mover();
        bool limite();
        int regresarX();
        int regresarY();
};

#endif // DISPARO_H
