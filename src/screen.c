#include "include/var.h"
#include "include/function.h"
#include "include/screen.h"
#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int dim_x, dim_y;                       // windows dimensions

void start_s()
{
    int x = 10, y = 10;

    initscr();                              // start ncurses

    getmaxyx(stdscr, dim_y, dim_x);         // get windows dimensions

    if (start_color() == ERR || !has_colors() || !can_change_color()) // start color
    {
        endwin();
        refresh();
        fputs("Could not use colors.", stderr);
        exit(EXIT_FAILURE);
    }

    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    attron(COLOR_PAIR(1));                  // apply color's configuration
    box(stdscr, 0, 0);                      // draw a box in the screen
    refresh();
    
    x = dim_x/2 - 2;
    y = dim_y/2;
    move(y, x);
    curs_set(0);                            // remove cursor
    printw("VECTOR");
    refresh();
    sleep(3);
    curs_set(1);
}

void move_c(int x, int y)
{
    move(y, x);
    refresh();
}

void clear_s()
{
    clear();
}

void print(const char *string)
{
    printw(string);
    refresh();
}

void scan(const char *type, void*var)
{
    scanw(type, var);
}

void refresh_s()
{
    refresh();
}

void exit_s()
{
    refresh();
    endwin();
}