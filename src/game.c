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
    WINDOW *win;

    if ((win = initscr()) == NULL) // inicia ncurses
    {
        fputs("Could not initialize screen.", stderr);
        exit(EXIT_FAILURE);
    }

    // inicializar colores
    if (start_color() == ERR || !has_colors() || !can_change_color())
    {
        delwin(win);
        endwin();
        refresh();
        fputs("Could not use colors.", stderr);
        exit(EXIT_FAILURE);
    }

    init_pair(1, P.cstate, COLOR_BLACK); // texto amarillo sobre fondo negro
    init_pair(2, COLOR_WHITE, COLOR_BLACK);
    // attron(COLOR_PAIR(1));//activa pareja 1
    wbkgd(win, COLOR_PAIR(1));
    x = 1;
    y = 1;
    wmove(win, y, x);
    wprintw(win, "%s", P.name);
    box(win, 0, 0);
    wrefresh(win);
    keypad(stdscr, 1); // activa teclas especiales
    cbreak();          // pulsacion instantanea
    refresh();
    x = 2;
    y = 2;
    wmove(win, y, x);
    curs_set(0);
    wprintw(win, "^");

    while (1)
    {
        noecho();
        key = getch();

        if (key == KEY_UP) // up
        {
            wmove(win, y, x);
            wprintw(win, " ");
            y--;
            wmove(win, y, x);
            wprintw(win, "^");
            wrefresh(win);
        }
        if (key == KEY_DOWN) // down
        {
            wmove(win, y, x);
            wprintw(win, " ");
            y++;
            wmove(win, y, x);
            wprintw(win, "v");
            wrefresh(win);
        }
        if (key == KEY_LEFT) // left
        {
            wmove(win, y, x);
            wprintw(win, " ");
            x--;
            wmove(win, y, x);
            wprintw(win, "<");
            wrefresh(win);
        }
        if (key == KEY_RIGHT) // right
        {
            wmove(win, y, x);
            wprintw(win, " ");
            x++;
            wmove(win, y, x);
            wprintw(win, ">");
            wrefresh(win);
        }
        if (key == 27)
        {
            wbkgd(win, COLOR_PAIR(2));
            break;
        }
    }
    delwin(win);
    clear();
    endwin();
    refresh();
    return;
}