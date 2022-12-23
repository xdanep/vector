#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include "include/game.h"
#include "include/sound.h"
#include "include/screen.h"
#include "include/gameplay.h"

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
    int xp[100], yp[100], i, ie = 5, ie2 = 4, ie3 = 3;

    VECTOR Pl;
    ENEMY E1, E2, E3;

    E1.xv = 2;
    E1.yv = dim_y / 2 - 1;
    E1.appear = 1;

    E2.xv = 2;
    E2.yv = dim_y / 2 - 1;
    E2.appear = 0;

    E3.xv = 2;
    E3.yv = dim_y / 2 - 1;
    E3.appear = 0;

    bonusp_p(xp, yp, 100);

    clear_s(); // clear screen

    if (O.mstate)
        sound(SONG2, SOUNDFREQ, SOUNDBUFLEN); // start music

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
    Pl.xv = dim_x / 2;
    Pl.yv = dim_y / 2;

    move(Pl.yv, Pl.xv);

    curs_set(0); // remove cursor

    sprint("|");

    move(Pl.yv - 1, Pl.xv);
    sprint("^");

    set_escdelay(0);

    noecho(); // no writing echo in terminal

    while (1)
    {
        //  Restart bonus position coordinates
        if(i == 99)
        bonusp_p(xp, yp, 100);

        key = getch(); // captching key writed

        // exiting game
        if (key == 27)
        {
            attron(COLOR_PAIR(2)); // white text on black background
            break;
        }

        // Printing bonus
        attron(COLOR_PAIR(4));
        print_bonus(xp[i], yp[i]);

        // Cleaning vectors
        clean_vector(Pl.xv, Pl.yv);

        clean_vector(E1.xv, E1.yv);

        if(E2.appear)
        clean_vector(E2.xv, E2.yv);

        if(E3.appear)
        clean_vector(E3.xv, E3.yv);

        // Moving vectors
        attron(COLOR_PAIR(1));
        move_vector(key, &Pl, &score);

        attron(COLOR_PAIR(2));
        move_enemy(&E1, &Pl);

        if(E2.appear)
        move_enemy(&E2, &Pl);

        if(E3.appear)
        move_enemy(&E3, &Pl);

        // Increment score
        if (Pl.xv == xp[i] && Pl.yv == yp[i])
        {
            i++;
            score += 100;
            
            // Second enemy
            if(score >= 1000)
            {
                score+=100;
                E2.appear = 1;
            }   

            // Third enemy
            if(score >= 3000)
            {
                score+=200;
                E3.appear = 1;
            }
            /*
            if (ie < 95)
                ie += 2;

            else
                ie-=70;

            clean_vector(E1.xv, E1.yv);

            if(E2.appear)
            clean_vector(E2.xv, E2.yv);

            if(E3.appear)
            clean_vector(E3.xv, E3.yv);

            E1.xv = xp[ie];
            E1.yv = yp[ie];

            if(E2.appear)
            {   
                E2.xv = xp[ie2];
                E2.yv = yp[ie2];
            }

            if(E3.appear)
            {
                E3.xv = xp[ie3];
                E3.yv = yp[ie3];
            }

            attron(COLOR_PAIR(2));
            move_enemy(&E1, &Pl);

            if(E2.appear)
            move_enemy(&E2, &Pl);

            if(E3.appear)
            move_enemy(&E3, &Pl);
            */
        }

        // Game over by enemy collision
        if (E1.xv == Pl.xv && E1.yv == Pl.yv)
        {
            move(dim_y / 2, dim_x / 2 - 4);
            printw("GAME OVER");
            refresh();

            if (O.mstate)
            {
                cleansound();
                wsound(SONG3, SOUNDFREQ, SOUNDBUFLEN); // starting main menu music
                sleep(1);
                cleansound();   // closing vlc
            }
            sleep(2);

            attron(COLOR_PAIR(2)); // white text on black background
            break;
        }

        if (E2.appear && E2.xv == Pl.xv && E2.yv == Pl.yv)
        {
            move(dim_y / 2, dim_x / 2 - 4);
            printw("GAME OVER");
            refresh();

            if (O.mstate)
            {
                cleansound();
                wsound(SONG3, SOUNDFREQ, SOUNDBUFLEN); // starting main menu music
                sleep(1);
                cleansound();   // closing vlc
            }
            sleep(2);

            attron(COLOR_PAIR(2)); // white text on black background
            break;
        }

        if (E3.appear && E3.xv == Pl.xv && E3.yv == Pl.yv)
        {
            move(dim_y / 2, dim_x / 2 - 4);
            printw("GAME OVER");
            refresh();
            
            if (O.mstate)
            {
                cleansound();
                wsound(SONG3, SOUNDFREQ, SOUNDBUFLEN); // starting main menu music
                sleep(1);
                cleansound();   // closing vlc
            }
            sleep(2);

            attron(COLOR_PAIR(2)); // white text on black background
            break;
        }

        clean_score();

        // increment score
        move(1, dim_x - 6); // set cursor position
        score++;

        // if (score < 0)
        // {
        //     move(dim_y / 2, dim_x / 2 - 4);
        //     printw("GAME OVER");
        //     refresh();

        //     sleep(2);
        //     attron(COLOR_PAIR(2)); // white text on black background
        //     break;
        // }

        // Printing score
        attron(COLOR_PAIR(4));
        printw("%ld", score);
    }

    if (O.mstate)
    {
        cleansound();   // closing vlc
        sound(SONG1, SOUNDFREQ, SOUNDBUFLEN); // starting main menu music
    }

    // restoring default screen options
    clear_s();
    echo();
    curs_set(1);
    keypad(stdscr, 0);
    refresh();

    // if (score < 0)
    //     score = 0;

    return score;
}