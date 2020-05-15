#ifndef DISPARO2_H
#define DISPARO2_H


class Disparo2
{
    int x;
    int y;
    int dir;
    bool st;
    public:
        Disparo2(int, int, int);
        void gotoxy(int, int);
        void mover();
        bool limite();
        int regresarX();
        int regresarY();
};

#endif // DISPARO2_H
