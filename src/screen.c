#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>

#include "include/screen.h"

int dim_x, dim_y; // windows dimensions

// Start ncurses
void start_s()
{
    int x = 10, y = 10;

    initscr(); // start ncurses

    getmaxyx(stdscr, dim_y, dim_x); // get windows dimensions

    if (start_color() == ERR || !has_colors() || !can_change_color()) // start color
    {
        endwin(); // close ncurses
        refresh();
        fputs("Could not use colors.", stderr);
        exit(EXIT_FAILURE);
    }

    init_pair(1, COLOR_WHITE, COLOR_BLACK); // set white text on black background
    attron(COLOR_PAIR(1));                  // apply color's configuration
    box(stdscr, 0, 0);                      // draw a box in the screen
    refresh();

    x = dim_x / 2 - 2;
    y = dim_y / 2;
    move(y, x);
    curs_set(0); // remove cursor
    printw("VECTOR");
    refresh();
    sleep(3);
    curs_set(1);
}

// Move pointer
void move_c(int x, int y)
{
    move(y, x);
    refresh();
}

// Clear screen
void clear_s()
{
    clear();
}

// Print in stdout
void print(const char *type, void *var)
{
    printw(type, var);
    refresh();
}

// Print a string in stdout
void sprint(const char *string)
{
    printw("%s", string);
    refresh();
}

// Scan from stdin
void scan(const char *type, void *var)
{
    scanw(type, var);
}

// Refresh window
void refresh_s()
{
    refresh();
}

// Exit ncurses
void exit_s()
{
    refresh();
    endwin();
}