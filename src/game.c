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

    clear_s();                // clear screen
    move_c(0, dim_y / 2 - 2); // move pointer

    sprint("Nickname (Max 20 characters): ");
    setbuf(stdin, NULL);   // clear stdin buffer
    getstr(P->name);       // introduce player's name
    strtok(P->name, "\n"); // clear \n of getstr

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
long int start()
{
    int x = 10, y = 10;
    int key;
    long int score = 0;

    clear_s(); // clear screen

    if (O.mstate)
        game_music(); // start music

    // setting colors
    init_pair(1, P.cstate, COLOR_BLACK);      // user's choice text on black background
    init_pair(2, COLOR_WHITE, COLOR_BLACK);   // white text on black background
    init_pair(3, COLOR_MAGENTA, COLOR_BLACK); // magenta text on black background
    init_pair(4, COLOR_CYAN, COLOR_BLACK);    // cyan text on black background

    attron(COLOR_PAIR(3)); // apply magenta box on black background
    box(stdscr, 0, 0);     // draw a box in the screen

    // print nickname
    attron(COLOR_PAIR(4)); // apply cyan text on black background
    x = 1;
    y = 1;
    move_c(y, x); // set cursor position
    sprint(P.name);

    attron(COLOR_PAIR(1)); // apply user's choice text on black background

    refresh_s(); // refresh window

    keypad(stdscr, 1); // activate all keys
    cbreak();          // instant push
    refresh_s();       // refresh window

    // set cursor position
    x = dim_x / 2;
    y = dim_y / 2;
    move(y, x);

    curs_set(0); // remove cursor

    sprint("|");

    move(y-1, x);
    sprint("^");

    set_escdelay(0.1);

    while (1)
    {
        noecho(); // no writing echo in terminal
        key = getch(); // captching key writed

        // remove previous vector position
        move(y-1, x-1);
        printw(" ");
        move(y-1, x);
        printw(" ");
        move(y-1, x+1);
        printw(" ");

        move(y, x-1);
        printw(" ");
        move(y, x);
        printw(" ");
        move(y, x+1);
        printw(" ");

        move(y+1, x-1);
        printw(" ");
        move(y+1, x);
        printw(" ");
        move(y+1, x+1);
        printw(" ");

        // exiting game
        if (key == 27)
        {
            attron(COLOR_PAIR(2)); // white text on black background
            break;
        }

        // moving up
        if (key == KEY_UP) 
        {
            y--;
            if (y == 2)
            {    
                y++;
                score-=2;
            }
            move(y, x);
            printw("|");

            move(y-1,x);
            printw("^");
        }

        // moving down
        if (key == KEY_DOWN) 
        {
            y++;
            if (y == (dim_y - 2))
            {    
                y--;
                score-=2;
            }
            move(y, x);
            printw("|");

            move(y+1,x);
            printw("v");
        }

        // moving left
        if (key == KEY_LEFT)
        {
            x--;
            if (x == 1)
            {
                x++;
                score-=2;
            }
            move(y, x);
            printw("-");

            move(y, x-1);
            printw("<");
        }

        // moving right
        if (key == KEY_RIGHT)
        {
            x++;
            if (x == (dim_x - 2))
            {
                x--;
                score-=2;
            }
            move(y, x);
            printw("-");

            move(y, x+1);
            printw(">");
        }

        //clean score
        move(1, dim_x-5);
        printw(" ");
        move(1, dim_x-4);
        printw(" ");
        move(1, dim_x-3);
        printw(" ");
        move(1, dim_x-2);
        printw(" ");

        // increment score
        move(1, dim_x-6); // set cursor position
        score++;
        
        if (score < 0)
        {
            move(dim_y / 2, dim_x / 2 - 4);
            printw("GAME OVER");
            refresh();

            sleep(2);
            break;
        }

        printw("%ld", score);
    }

    if (O.mstate)
    {
        exit_vlc(); //closing vlc
        init_music(); // starting main menu music
    }

    // restoring default screen options
    clear_s();
    echo();
    curs_set(1);
    keypad(stdscr, 0);
    refresh();

    if(score < 0)
    score = 0;

    return score;
}