#include "var.h"
#include "function.h"
#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>

void ngame(PLAYER*P)
{
    unsigned short int sel;

    system("clear");//activate for linux
    //system("CLS");//activate for windows
    printf("Nickname (Max 20 characters): ");
    //fflush(stdin);//for windows
    setbuf(stdin,NULL);//for linux
    scanf("%s", P->name);
    printf("Choose your color:\n");
    printf("1. Yellow\n2. Green\n3. Blue\n4. Red\n");
    printf("::");
    scanf("%hu", &sel);

    if(sel == 1)
    P->cstate = (COLOR) 3;

    else if(sel == 2)
    P->cstate = (COLOR) 2;

    else if(sel == 3)
    P->cstate = (COLOR) 4;

    else if(sel == 4)
    P->cstate = (COLOR) 1;

    else
    {
        printf("Default: Yellow");
        P->cstate = (COLOR) 3;
    }
}

void start()
{
    int x = 10, y = 10;
    int key;

    initscr(); //inicia ncurses

    //inicializar colores
    if(has_colors())
    start_color();
    init_pair(1, P.cstate, COLOR_BLACK);//texto amarillo sobre fondo negro
    init_pair(2, COLOR_WHITE, COLOR_BLACK);
    attron(COLOR_PAIR(1));//activa pareja 1
    keypad(stdscr, 1); //activa teclas especiales
    cbreak(); //pulsacion instantanea
    printw("Welcome %s, press ESC to exit to main menu.\n", P.name);
    refresh();
    move(y, x);
    printw("^");

    while(1)
    {   
        noecho();
        key = getch();
        
        if(key == KEY_UP)//up
        {
            move(y, x);
            printw(" ");
            y--;
            move(y, x);
            printw("^");
            refresh();
        }
        if(key == KEY_DOWN)//down
        {
            move(y, x);
            printw(" ");
            y++;
            move(y, x);
            printw("v");
        }
        if(key == KEY_LEFT)//left
        {
            move(y, x);
            printw(" ");
            x--;
            move(y, x);
            printw("<");
            refresh();
        }
        if(key == KEY_RIGHT)//right
        {
            move(y, x);
            printw(" ");
            x++;
            move(y, x);
            printw(">");
            refresh();
        }
        if(key == 27)
        {
            attron(COLOR_PAIR(2));
            break;
        }
    }
    clear();
    endwin();
    return;
}
//Comenzar a implementar los proximos funcionamientos