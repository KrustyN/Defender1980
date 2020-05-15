#define _WIN32_WINNT 0x0502
#include <windows.h>
#include <iostream>
#include <conio.h>
#include <bits/stdc++.h>
#include <Jugador.h>
#include <Disparo.h>
#include <Baiter.h>
#include <Bomber.h>
#include <Lander.h>
#include <Mutant.h>
#include <Pod.h>
#include <Swarmer.h>
#include <Astronauta.h>
#include <list>

using namespace std;

void MostrarCursor(bool visible)
{
    HANDLE cursor = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO     cursorInfo;
    GetConsoleCursorInfo(cursor, &cursorInfo);
    cursorInfo.bVisible = visible;
    SetConsoleCursorInfo(cursor, &cursorInfo);
}

void gotoxy(int x, int y)
{
    HANDLE hID;
    hID = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD cPos;
    cPos.X = x;
    cPos.Y = y;
    SetConsoleCursorPosition(hID, cPos);
}

void HUD()
{

    for(int i = 2; i < 193; i++)
    {
        gotoxy(i, 6);
        printf("%c", 205);
        gotoxy(i, 34);
        printf("%c", 205);
    }
    for(int i = 0; i < 6; i++)
    {
        gotoxy(78, i);
        printf("%c", 186);
        gotoxy(117, i);
        printf("%c", 186);
    }
    for(int i = 7; i < 34; i++)
    {
        gotoxy(2, i);
        printf("%c", 186);
        gotoxy(193, i);
        printf("%c", 186);
    }
    gotoxy(78, 0);
    printf("%c", 201);
    gotoxy(117, 0);
    printf("%c", 187);
    gotoxy(2, 6);
    printf("%c", 201);
    gotoxy(193, 6);
    printf("%c", 187);
    gotoxy(78, 6);
    printf("%c", 202);
    gotoxy(117, 6);
    printf("%c", 202);
    gotoxy(2, 34);
    printf("%c", 200);
    gotoxy(193, 34);
    printf("%c", 188);
}

void Borrar()
{
    COORD pos;
    pos.X = 0;
    pos.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Iniciar()
{
    Explosion muerte;
    Astronauta ast;
    Jugador nav(95, 15, true, 3, muerte);
    Baiter bt1(85, 10, muerte, nav);
    Bomber bm1(135, 25, muerte, nav);
    Lander ln1(125, 30, muerte, nav, ast);
    Mutant mt1(115, 20, muerte, nav);
    Pod pd1(100, 10, muerte, nav);
    Swarmer sw1(90, 10, muerte, nav);
    nav.dibujar(nav.regresarDir());
    bt1.dibujar();
    bm1.dibujar();
    ln1.dibujar();
    mt1.dibujar();
    pd1.dibujar();
    sw1.dibujar();
    nav.vidasRestantes();
    HUD();
    list<Disparo*> dispJ;
    list<Disparo2*> dispE;
    list<Disparo*>::iterator idDJ;
    list<Disparo2*>::iterator idDE;
    bool vida = true;
    while(vida)
    {
        if(kbhit())
        {
            if (GetAsyncKeyState(0x4F))
            {
                dispJ.push_back(new Disparo(nav.regresarX(), nav.regresarY() + 1, nav.regresarDir()));
                dispE.push_back(new Disparo2(bt1.regresarX(), bt1.regresarY(), bt1.apuntar(nav.regresarX(), nav.regresarY())));
            }
        }
        for(idDJ = dispJ.begin(); idDJ != dispJ.end(); idDJ++)
        {
            (*idDJ)->mover();
            if((*idDJ)->limite())
            {
                gotoxy((*idDJ)->regresarX(),(*idDJ)->regresarY());
                printf("     ");
                delete(*idDJ);
                idDJ = dispJ.erase(idDJ);
            }
        }
        for(idDE = dispE.begin(); idDE != dispE.end(); idDE++)
        {
            (*idDE)->mover();
            if((*idDE)->limite())
            {
                gotoxy((*idDE)->regresarX(),(*idDE)->regresarY());
                printf(" ");
                delete(*idDE);
                idDE = dispE.erase(idDE);
            }
        }
        nav.mover();
        bt1.mover(nav.regresarX(), nav.regresarY());
        bm1.mover(nav.regresarX(), nav.regresarY());
        ln1.mover(nav.regresarX(), nav.regresarY());
        mt1.mover(nav.regresarX(), nav.regresarY());
        pd1.mover(nav.regresarX(), nav.regresarY());
        sw1.mover(nav.regresarX(), nav.regresarY());
        Sleep(30);
    }
}

void Creditos(string creditos[20])
{
    int numOpc = 0, ind, rept = 1, cont, men;
    for(int i = 0; i <= 20; i++)
    {
        MostrarCursor(false);
        cont = 1;
        ind = 20;
        while(cont < rept)
        {
            ind--;
            men = ind;
            cont++;
        }
        while(men < 20)
        {
            cout << creditos[men] << endl;
            men++;
        }
        Sleep(50);
        if(i < 20)
            system("CLS");
        rept++;
    }

    for(int i = 0; i < 13; i++)
        cout << endl;
    cout << "                                                                           Presiona P para regresar al menu principal";
    bool ciclo = true;
    while(ciclo)
    {
        if(kbhit())
        {
            char exit = getch();
            if(exit == 'p' || exit == 'P')
                ciclo = false;
        }
    }
}

void Salir()
{
    Borrar();
    exit(0);
}

void Instrucciones()
{
    bool rept = true, tmpRep = true;
    string objet = "??                                                                                              OBJETIVO:?    El objetivo del juego es destruir a los enemigos que vienen en oleadas, al mismo tiempo de que se deben proteger a los astronautas de la superficie. Al vencer a todos los enemigos de la?                                                                                oleada, se avanza al siguiente nivel.?    El jugador cuenta con tres naves para avanzar en el juego, las cuales pueden aumentar llegando alcanzando los puntos necesarios. Una nave se pierde al tocar a un enemigo o una bala, en?                                                                             caso de quedarse sin naves el juego termina.";
    string contr = "??                                                                                              CONTROLES:?                                                                             W, S: Ganar y perder altitud, respectivamente.?                                                                     A, D: Moverse hacia la izquierda y derecha, respectivamente.?                                                                                         O: Boton de disparo.?                                                                                           P: Lanzar bomba.?                                                                                         ENTER: Pausa el juego.??                                                                                              ENEMIGOS:?";
    string enem1A = "          	      .    	    .		     .";
    string enem2A = "          	     :0:	   :^:		   {-I-}";
    string enem3A = "          	   LANDER	  MUTANT	  BAITER";
    string enem4A = "          	 150 PUNTOS	150 PUNTOS	200 PUNTOS";
    string enem5A = "          	      [O]          *0*";
    string enem6A = "          	     [O]           ***		     *";
    string enem7A = "          	   BOMBER	   POD	  	  SWARMER";
    string enem8A = "          	 150 PUNTOS	150 PUNTOS	200 PUNTOS";
    string enem1B = "          	      _    	    _		     _";
    string enem2B = "          	     0:0	   ^:^		   {I-I}";
    string enem3B = "          	   LANDER	  MUTANT	  BAITER";
    string enem4B = "          	 150 PUNTOS	150 PUNTOS	200 PUNTOS";
    string enem5B = "          	      [*]          0+0";
    string enem6B = "          	     [*]           +++		     +";
    string enem7B = "          	   BOMBER	   POD	  	  SWARMER";
    string enem8B = "          	 150 PUNTOS	150 PUNTOS	200 PUNTOS";
    int lonObj = objet.length(), lonCtl = contr.length(), est = 0;
    char arrObjet[lonObj + 1], arrContr[lonCtl + 1];
    string enem1, enem2, enem3, enem4, enem5, enem6, enem7, enem8;
    strcpy(arrObjet, objet.c_str());
    strcpy(arrContr, contr.c_str());
    while(rept)
    {
        Borrar();
        for (int i = 0; i < lonObj; i++)
        {
            if (tmpRep)
                Sleep(5);
            if(arrObjet[i] == '?')
                cout << endl;
            else
                cout << arrObjet[i];
        }
        for (int i = 0; i < lonCtl; i++)
        {
            if(tmpRep)
                Sleep(5);
            if(arrContr[i] == '?')
                cout << endl;
            else
                cout << arrContr[i];
        }
        tmpRep = false;
        cout << endl;
        cout << "                                                                      "; printf("  %c%c%c",174,207,175); cout << "                      "; printf("%c%c%c",174,173,175);  cout << "                      "; printf(" %c%c%c ",242,242,242); cout << endl;
        cout << "                                                                      "; printf("  %c%c%c",47,179,92); cout << "                      "; printf("%c%c%c",47,179,92); cout << "                      "; printf("%c%c%c%c%c",47,61,61,61,92); cout << endl;
        cout << "                                                                       "; printf("LANDER"); cout << "                   "; printf("MUTANT"); cout << "                   "; printf("BAITER"); cout << endl;
        cout << "                                                                     "; printf("150 PUNTOS"); cout << "               "; printf("200 PUNTOS"); cout << "               "; printf("200 PUNTOS"); cout << endl;
        cout << endl;
        cout << "                                                                      "; printf("  %c%c%c",91,254,93); cout << "                      "; printf("%c%c%c",195,207,180);  cout << "                      "; printf("  %c  ",207); cout << endl;
        cout << "                                                                      "; printf(" %c%c%c ",91,254,93); cout << "                      "; printf("%c%c%c",92,242,47); cout << "                      "; printf("  %c%  ",238); cout << endl;
        cout << "                                                                       "; printf("BOMBER"); cout << "                   "; printf(" POD  "); cout << "                   "; printf("SWARMER"); cout << endl;
        cout << "                                                                     "; printf("150 PUNTOS"); cout << "               "; printf("200 PUNTOS"); cout << "               "; printf("200 PUNTOS"); cout << endl;
        cout << endl;
        for(int i = 0; i < 6; i++)
            cout << endl;
        cout << "                                                                           Presiona P para regresar al menu principal";
        if(kbhit())
        {
            char exit = getch();
            if(exit == 'p' || exit == 'P')
                rept = false;
        }
        Sleep(250);
    }
}

void Titulo(string defender[20])
{
    int numOpc = 0, ind, rept = 1, cont, men;
    for(int i = 0; i <= 20; i++)
    {
        MostrarCursor(false);
        cont = 1;
        ind = 20;
        while(cont < rept)
        {
            ind--;
            men = ind;
            cont++;
        }
        while(men < 20)
        {
            cout << defender[men] << endl;
            men++;
        }
        Sleep(25);
        if(i < 20)
            system("CLS");
        rept++;
    }
}

void Menu(string menuOpc[9], string defender[20], string creditos[15])
{
    int numOpc = 0, iD = 1, men = 20, spark = 0, sprRep = 0;
    string select = "                                                                                        O---=============---O";
    bool jugar = true, mostrar = false;
    char tecla;
    while(jugar)
    {
        MostrarCursor(false);
        while(men < 20)
        {
            cout << defender[men] << endl;
            men++;
        }
        while(spark < 1)
        {
            system("Color 01");
            Sleep(50);
            system("Color 02");
            Sleep(50);
            spark++;
            sprRep++;
        }
        if (sprRep < 5)
            spark = 0;
        else
        {
            mostrar = true;
            spark = 1;
        }
        cout << endl;
        men = 0;
        while(numOpc < 9 && mostrar)
        {
            cout << menuOpc[numOpc] << endl;
            numOpc++;
        }
        if(mostrar)
        {
            for(int i = 0; i < 3; i++)
                cout << endl;
            cout << "                                                                   Presiona W, S para desplazarte por el menu, O para seleccionar";
        }
        system("CLS");
        numOpc = 0;
        if(kbhit())
        {
            char tecla = getch();
            switch(tecla)
            {
                case 'W':
                if (iD > 1)
                {
                    menuOpc[iD - 1] = "";
                    menuOpc[iD + 1] = "";
                    iD = iD - 2;
                    menuOpc[iD - 1] = select;
                    menuOpc[iD + 1] = select;
                }
                else
                {
                    menuOpc[iD - 1] = "";
                    menuOpc[iD + 1] = "";
                    iD = 7;
                    menuOpc[iD - 1] = select;
                    menuOpc[iD + 1] = select;
                } break;
                case 'w':
                if (iD > 1)
                {
                    menuOpc[iD - 1] = "";
                    menuOpc[iD + 1] = "";
                    iD = iD - 2;
                    menuOpc[iD - 1] = select;
                    menuOpc[iD + 1] = select;
                }
                else
                {
                    menuOpc[iD - 1] = "";
                    menuOpc[iD + 1] = "";
                    iD = 7;
                    menuOpc[iD - 1] = select;
                    menuOpc[iD + 1] = select;
                } break;
                case 'S':
                if (iD < 7)
                {
                    menuOpc[iD - 1] = "";
                    menuOpc[iD + 1] = "";
                    iD = iD + 2;
                    menuOpc[iD - 1] = select;
                    menuOpc[iD + 1] = select;
                }
                else
                {
                    menuOpc[iD - 1] = "";
                    menuOpc[iD + 1] = "";
                    iD = 1;
                    menuOpc[iD - 1] = select;
                    menuOpc[iD + 1] = select;
                } break;
                case 's':
                if (iD < 7)
                {
                    menuOpc[iD - 1] = "";
                    menuOpc[iD + 1] = "";
                    iD = iD + 2;
                    menuOpc[iD - 1] = select;
                    menuOpc[iD + 1] = select;
                }
                else
                {
                    menuOpc[iD - 1] = "";
                    menuOpc[iD + 1] = "";
                    iD = 1;
                    menuOpc[iD - 1] = select;
                    menuOpc[iD + 1] = select;
                } break;
                case 'o':
                switch(iD)
                {
                    case 1: Iniciar(); break;
                    case 3: Instrucciones(); break;
                    case 5: Creditos(creditos); break;
                    case 7: Salir(); break;
                    default: break;
                }
                break;
                case 'O':
                switch(iD)
                {
                    case 1: Iniciar(); break;
                    case 3: Instrucciones(); break;
                    case 5: Creditos(creditos); break;
                    case 7: Salir(); break;
                    default: break;
                }
                break;
                default: break;
            }
        }
    }
}

int main()
{
    system("Color 02");
    //Variables de resolución 35*195 caracteres
    int wth = 1440, hth = 600, posX = 40, posY = 100;
    HWND hwnd = GetConsoleWindow();
    if( hwnd != NULL )
    {
        MoveWindow(hwnd, posX, posY, wth, hth, TRUE);
    }

    //Arreglo opciones
    string menuOpc[9] = {
    "                                                                                        O---=============---O",
    "                                                                                            Iniciar Juego",
    "                                                                                        O---=============---O",
    "                                                                                            Instrucciones",
    "",
    "                                                                                               Creditos",
    "",
    "                                                                                                Salir",
    ""};

    //Arreglo titulo
    string defender[20] = {
    "",
    "",
    "",
    "",
    "             #############      ##########################################################################        #####################      #######################################",
    "             #::::::::::::###   #::::::::::::::::::::##::::::::::::::::::::##::::::::::::::::::::##:::::::#       #::::::##::::::::::::###   #::::::::::::::::::::##::::::::::::::::#",
    "             #:::::::::::::::## #::::::::::::::::::::##::::::::::::::::::::##::::::::::::::::::::##::::::::#      #::::::##:::::::::::::::## #::::::::::::::::::::##::::::######:::::#",
    "             ###:::::#####:::::###::::::#########::::###::::::#########::::###::::::#########::::##:::::::::#     #::::::####:::::#####:::::###::::::#########::::###:::::#     #:::::#",
    "               #:::::#    #:::::# #:::::#       ######  #:::::#       ######  #:::::#       #######::::::::::#    #::::::#  #:::::#    #:::::# #:::::#       ######  #::::#     #:::::#",
    "               #:::::#     #:::::##:::::#               #:::::#               #:::::#             #:::::::::::#   #::::::#  #:::::#     #:::::##:::::#               #::::#     #:::::#",
    "               #:::::#     #:::::##::::::##########     #::::::##########     #::::::##########   #:::::::#::::#  #::::::#  #:::::#     #:::::##::::::##########     #::::######:::::#",
    "               #:::::#     #:::::##:::::::::::::::#     #:::::::::::::::#     #:::::::::::::::#   #::::::# #::::# #::::::#  #:::::#     #:::::##:::::::::::::::#     #:::::::::::::##",
    "               #:::::#     #:::::##:::::::::::::::#     #:::::::::::::::#     #:::::::::::::::#   #::::::#  #::::#:::::::#  #:::::#     #:::::##:::::::::::::::#     #::::######:::::#",
    "               #:::::#     #:::::##::::::##########     #::::::##########     #::::::##########   #::::::#   #:::::::::::#  #:::::#     #:::::##::::::##########     #::::#     #:::::#",
    "               #:::::#     #:::::##:::::#               #:::::#               #:::::#             #::::::#    #::::::::::#  #:::::#     #:::::##:::::#               #::::#     #:::::#",
    "               #:::::#    #:::::# #:::::#       ######  #:::::#               #:::::#       #######::::::#     #:::::::::#  #:::::#    #:::::# #:::::#       ######  #::::#     #:::::#",
    "             ###:::::#####:::::###::::::########:::::###:::::::##           ##::::::########:::::##::::::#      #::::::::####:::::#####:::::###::::::########:::::###:::::#     #:::::#",
    "             #:::::::::::::::## #::::::::::::::::::::##::::::::##           #::::::::::::::::::::##::::::#       #:::::::##:::::::::::::::## #::::::::::::::::::::##::::::#     #:::::#",
    "             #::::::::::::###   #::::::::::::::::::::##::::::::##           #::::::::::::::::::::##::::::#        #::::::##::::::::::::###   #::::::::::::::::::::##::::::#     #:::::#",
    "             #############      #################################           ##############################         ####################      ##############################     #######"};
    string creditos[20] = {
    "",
    "",
    "",
    "                                                                               ___  _____________  _____  ________",
    "                                                                              / _ |/ __/ __/ __/ |/ / _ |/ __/ _  |",
    "                                                                             / // / _// _// _//    / // / _// , _/",
    "                                                                            /____/___/_/ /___/_/|_/____/___/_/|_| ",
    "",
    "",
    "                                                                       BASADO EN 'DEFENDER (1981)' DE WILLIAM ELECTRONICS",
    "",
    "                                                                          UNIVERSIDAD AUTONOMA DE BAJA CALIFORNIA SUR",
    "",
    "                                                                      DEPARTAMENTO ACADEMICO DE CIENCIAS COMPUTACIONALES",
    "",
    "                                                                             INGENIERIA EN DESARROLLO DE SOFTWARE",
    "",
    "                                                                               BRUNO ALEJANDRO ENCARNACION VARO",
    "",
    "                                                                                     RUBEN JIMENEZ RAMIREZ"};
    Titulo(defender);
    Menu(menuOpc, defender, creditos);
    return 0;
}

void Jugar()
{
}

