#define _WIN32_WINNT 0x0502
#include <windows.h>
#include <iostream>
#include <conio.h>
#include <bits/stdc++.h>

using namespace std;

void MostrarCursor(bool visible)
{
    HANDLE cursor = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO     cursorInfo;
    GetConsoleCursorInfo(cursor, &cursorInfo);
    cursorInfo.bVisible = visible;
    SetConsoleCursorInfo(cursor, &cursorInfo);
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
    string objet = "??    OBJETIVO:?    El objetivo del juego es destruir a los enemigos que vienen en oleadas, al mismo tiempo de que se deben proteger a los astronautas de la superficie. Al vencer a todos los enemigos de la?    oleada, se avanza al siguiente nivel.?    El jugador cuenta con tres naves para avanzar en el juego, las cuales pueden aumentar llegando alcanzando los puntos necesarios. Una nave se pierde al tocar a un enemigo o una bala, en?    caso de quedarse sin naves el juego termina.";
    string contr = "??    CONTROLES:?    W, S: Ganar y perder altitud, respectivamente.?    A, D: Moverse hacia la izquierda y derecha, respectivamente.?    O: Boton de disparo.?    P: Lanzar bomba.?    ENTER: Pausa el juego.??    ENEMIGOS:?";
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
        if (est == 0)
        {
            enem1 = enem1A;
            enem2 = enem2A;
            enem3 = enem3A;
            enem4 = enem4A;
            enem5 = enem5A;
            enem6 = enem6A;
            enem7 = enem7A;
            enem8 = enem8A;
            est = 1;
        }
        else if (est == 1)
        {
            enem1 = enem1B;
            enem2 = enem2B;
            enem3 = enem3B;
            enem4 = enem4B;
            enem5 = enem5B;
            enem6 = enem6B;
            enem7 = enem7B;
            enem8 = enem8B;
            est = 0;
        }
        cout << enem1 << endl;
        cout << enem2 << endl;
        cout << endl;
        cout << enem3 << endl;
        cout << enem4 << endl;
        cout << endl,
        cout << enem5 << endl;
        cout << enem6 << endl;
        cout << endl;
        cout << enem7 << endl;
        cout << enem8 << endl;
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
            system("Color 06");
            Sleep(50);
            system("Color 04");
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
                    case 3: Instrucciones(); break;
                    case 5: Creditos(creditos); break;
                    case 7: Salir(); break;
                    default: break;
                }
                break;
                case 'O':
                switch(iD)
                {
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
    //Variables de resolución 35*84 caracteres
    int wth = 1440, hth = 600, posX = 40, posY = 100;
    HWND hwnd = GetConsoleWindow();
    if( hwnd != NULL )
    {
        MoveWindow(hwnd, posX, posY, wth, hth, TRUE);
    }
    system("Color 04");

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


