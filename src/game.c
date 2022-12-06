#include "var.h"
#include "function.h"
#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>

void ngame(PLAYER *P)
{
    unsigned short int sel;

    system("clear"); // activate for linux
    // system("CLS");//activate for windows
    printf("Nickname (Max 20 characters): ");
    // fflush(stdin);//for windows
    setbuf(stdin, NULL); // for linux
    scanf("%s", P->name);
    printf("Choose your color:\n");
    printf("1. Yellow\n2. Green\n3. Blue\n4. Red\n");
    printf(">");
    scanf("%hu", &sel);

    if (sel == 1)
        P->cstate = (COLOR)3;

    else if (sel == 2)
        P->cstate = (COLOR)2;

    else if (sel == 3)
        P->cstate = (COLOR)4;

    else if (sel == 4)
        P->cstate = (COLOR)1;

    else
    {
        printf("Default: Yellow");
        P->cstate = (COLOR)3;
    }
}

void start()
{
    int x = 10, y = 10;
    int key;
    int dim_x, dim_y; // dimension de la ventana

    initscr(); // inicia ncurses

    getmaxyx(stdscr, dim_y, dim_x); // Obtengo las dimensiones

    // inicializar colores
    if (start_color() == ERR || !has_colors() || !can_change_color())
    {
        endwin();
        refresh();
        fputs("Could not use colors.", stderr);
        exit(EXIT_FAILURE);
    }

    init_pair(1, P.cstate, COLOR_BLACK); // texto amarillo sobre fondo negro
    init_pair(2, COLOR_WHITE, COLOR_BLACK);
    attron(COLOR_PAIR(1)); // establecer color a la ventana

    x = 1;
    y = 1;
    move(y, x);

    box(stdscr, 0, 0);
    printw("%s", P.name);
    refresh();

    keypad(stdscr, 1); // activa teclas especiales
    cbreak();          // pulsacion instantanea
    refresh();

    x = 2;
    y = 2;
    move(y, x);

    curs_set(0);
    printw("^");

    while (1)
    {
        noecho();
        key = getch();

        if (key == KEY_UP) // up
        {
            move(y, x);
            printw(" ");
            y--;
            if (y == 1)
                y++;
            move(y, x);
            printw("^");
        }
        if (key == KEY_DOWN) // down
        {
            move(y, x);
            printw(" ");
            y++;
            if (y == (dim_y - 1))
                y--;
            move(y, x);
            printw("v");
        }
        if (key == KEY_LEFT) // left
        {
            move(y, x);
            printw(" ");
            x--;
            if (x == 0)
                x++;
            move(y, x);
            printw("<");
        }
        if (key == KEY_RIGHT) // right
        {
            move(y, x);
            printw(" ");
            x++;
            if (x == (dim_x - 1))
                x--;
            move(y, x);
            printw(">");
        }
        refresh();
        if (key == 27)
        {
            attron(COLOR_PAIR(2));
            break;
        }
    }
    clear();
    refresh();
    endwin();
    system("clear");

    return;
}