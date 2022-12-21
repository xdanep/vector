#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include "include/game.h"
#include "include/vlc.h"
#include "include/screen.h"

// Configure new game
void ngame(PLAYER *P)
{
    unsigned short int sel;

    clear_s();
    move_c(0, dim_y / 2 - 2);
    sprint("Nickname (Max 20 characters): ");
    setbuf(stdin, NULL);   // clear stdin buffer
    getstr(P->name);       // introduce player's name
    strtok(P->name, "\n"); // clear \n of fgets
    sprint("Choose your color:\n");
    sprint("1. Yellow\n2. Green\n3. Blue\n4. Red\n\n");
    sprint("> ");
    scan("%hu", &sel); // introduce player's color

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
        sprint("Default: Green");
        P->cstate = (COLOR)2;
    }
}

// Start game
void start()
{
    int x = 10, y = 10;
    int key;

    clear_s();

    if (O.mstate)
        game_music(); // start music

    init_pair(1, P.cstate, COLOR_BLACK); // green text on black background
    init_pair(2, COLOR_WHITE, COLOR_BLACK);
    init_pair(3, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(4, COLOR_CYAN, COLOR_BLACK);
    attron(COLOR_PAIR(3)); // apply color's configuration

    box(stdscr, 0, 0); // draw a box in the screen
    attron(COLOR_PAIR(4));

    x = 1;
    y = 1;
    move_c(y, x); // set cursor's position

    sprint(P.name);
    attron(COLOR_PAIR(1));
    refresh_s();
    keypad(stdscr, 1); // activate all keys
    cbreak();          // instant push
    refresh_s();       // update window's info

    x = dim_x / 2;
    y = dim_y / 2;
    move(y, x);

    curs_set(0); // remove cursor
    sprint("^");

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
        refresh_s();
        if (key == 27)
        {
            attron(COLOR_PAIR(2)); // white text on black background
            break;
        }
    }

    if (O.mstate)
    {
        exit_vlc();
        init_music();
        sleep(1);
    }

    clear_s();
    echo();
    curs_set(1);
    keypad(stdscr, 0);
    refresh();

    return;
}