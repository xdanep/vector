#include "var.h"
#include "function.h"
#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void ngame(PLAYER *P)
{
    unsigned short int sel;

    system("clear");
    printf("Nickname (Max 20 characters): ");
    setbuf(stdin, NULL);    // clear stdin buffer
    scanf("%s", P->name);   // introduce player's name
    printf("Choose your color:\n");
    printf("1. Yellow\n2. Green\n3. Blue\n4. Red\n\n");
    printf("> ");
    scanf("%hu", &sel);     // introduce player's color

    if (sel == 1)
        P->cstate = (COLOR)3; // yellow

    else if (sel == 2)
        P->cstate = (COLOR)2; // green

    else if (sel == 3)
        P->cstate = (COLOR)4; // blue

    else if (sel == 4)
        P->cstate = (COLOR)1; // red

    else
    {
        printf("Default: Green");
        P->cstate = (COLOR)2;
    }
}

void start()
{
    int x = 10, y = 10;
    int key;
    int dim_x, dim_y;                       // windows dimensions

    initscr();                              // start ncurses
    if(O.mstate) 
    game_music();                           // start music

    getmaxyx(stdscr, dim_y, dim_x);         // get windows dimensions

    if (start_color() == ERR || !has_colors() || !can_change_color()) // start color
    {
        endwin();
        refresh();
        fputs("Could not use colors.", stderr);
        exit(EXIT_FAILURE);
    }

    init_pair(1, P.cstate, COLOR_BLACK);    // green text on black background
    init_pair(2, COLOR_WHITE, COLOR_BLACK);
    attron(COLOR_PAIR(1));                  // apply color's configuration

    x = 1;
    y = 1;
    move(y, x);                             // set cursor's position

    box(stdscr, 0, 0);                      // draw a box in the screen
    printw("%s", P.name);
    refresh();

    keypad(stdscr, 1);                      // activate all keys
    cbreak();                               // instant push
    refresh();                              // update window's info

    x = 2;
    y = 2;
    move(y, x);

    curs_set(0);                            // remove cursor
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
            if (x == (dim_x - 2))
                x--;
            move(y, x);
            printw(">");
        }
        refresh();
        if (key == 27)
        {
            attron(COLOR_PAIR(2)); // white text on black background
            break;
        }
    }
    
    if(O.mstate)
    {
        exit_vlc();
        init_music();
    }

    clear();
    refresh();
    endwin();                      // end ncurses
    system("clear");

    return;
}