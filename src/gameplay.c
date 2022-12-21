#include <ncurses.h>
#include <stdlib.h>

#include "include/gameplay.h"
#include "include/screen.h"
#include "include/game.h"

// Remove previous vector position
void clean_vector(int x, int y)
{
    // up
    move(y - 1, x - 1);
    printw(" ");
    move(y - 1, x);
    printw(" ");
    move(y - 1, x + 1);
    printw(" ");

    // middle
    move(y, x - 1);
    printw(" ");
    move(y, x);
    printw(" ");
    move(y, x + 1);
    printw(" ");

    // down
    move(y + 1, x - 1);
    printw(" ");
    move(y + 1, x);
    printw(" ");
    move(y + 1, x + 1);
    printw(" ");
}

// Move vector position
void move_vector(int key, VECTOR *Pl, long int *score)
{
    int x, y;

    x = Pl->xv;
    y = Pl->yv;

    // moving up
    if (key == KEY_UP)
    {
        y--;
        if (y == 2)
        {
            y++;
            *score -= 2;
        }
        move(y, x);
        printw("|");

        move(y - 1, x);
        printw("^");
    }

    // moving down
    if (key == KEY_DOWN)
    {
        y++;
        if (y == (dim_y - 2))
        {
            y--;
            *score -= 2;
        }
        move(y, x);
        printw("|");

        move(y + 1, x);
        printw("v");
    }

    // moving left
    if (key == KEY_LEFT)
    {
        x--;
        if (x == 1)
        {
            x++;
            *score -= 2;
        }
        move(y, x);
        printw("\u2014");

        move(y, x - 1);
        printw("<");
    }

    // moving right
    if (key == KEY_RIGHT)
    {
        x++;
        if (x == (dim_x - 2))
        {
            x--;
            *score -= 2;
        }
        move(y, x);
        printw("\u2014");

        move(y, x + 1);
        printw(">");
    }

    Pl->xv = x;
    Pl->yv = y;
}

// Clean score
void clean_score()
{
    move(1, dim_x - 5);
    printw(" ");
    move(1, dim_x - 4);
    printw(" ");
    move(1, dim_x - 3);
    printw(" ");
    move(1, dim_x - 2);
    printw(" ");
}

void init_enemy(ENEMY *E)
{
    int i, j;

    while (1)
    {
        i = rand();

        if (i > 1 && i < (dim_x - 2))
            E->xv = i;

        if (j > 2 && j < (dim_y - 2))
            E->yv = j;
    }
}

void move_enemy(ENEMY *E, VECTOR *Pl)
{
    int x, y;

    x = E->xv;
    y = E->yv;

    // moving up
    if (Pl->yv < E->yv)
    {
        y--;
        if (y == 2)
        {
            y++;
        }
        move(y, x);
        printw("|");

        move(y - 1, x);
        printw("v");
    }

    // moving down
    if (Pl->yv > E->yv)
    {
        y++;
        if (y == (dim_y - 2))
        {
            y--;
        }
        move(y, x);
        printw("|");

        move(y + 1, x);
        printw("^");
    }

    // moving left
    if (Pl->xv < E->xv)
    {
        x--;
        if (x == 1)
        {
            x++;
        }
        move(y, x);
        printw("\u2014");

        move(y, x - 1);
        printw(">");
    }

    // moving right
    if (Pl->xv > E->xv)
    {
        x++;
        if (x == (dim_x - 2))
        {
            x--;
        }
        move(y, x);
        printw("\u2014");

        move(y, x + 1);
        printw("<");
    }

    E->xv = x;
    E->yv = y;
}