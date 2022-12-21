#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "include/menu.h"
#include "include/screen.h"
#include "include/vlc.h"

// Initialize OPTION structure
void init_option(OPTION *O)
{
    O->lstate = (LANGUAGE)0;
    O->mstate = (MUSIC)1;
}

// Get language options
void lang_option(OPTION *O)
{
    unsigned short int sel = 3;

    printf("Select language:\n0. English\n1. Spanish\n2. Portuguese\n\n");
    printf("> ");
    scanf("%hu", &sel);

    if (sel == 0)
        O->lstate = (LANGUAGE)0;
    else if (sel == 1)
        O->lstate = (LANGUAGE)1;
    else if (sel == 2)
        O->lstate = (LANGUAGE)2;
    else
    {
        printf("Selected default (ENGLISH), press enter to continue\n");
        getchar();
        O->lstate = (LANGUAGE)0;
    }
}

// Display main menu
void menu()
{
    move_c(dim_x / 2 - 8, dim_y / 2 - 2);
    sprint("1. Start new game\n");
    move_c(dim_x / 2 - 8, dim_y / 2 - 1);
    sprint("2. Load game\n");
    move_c(dim_x / 2 - 8, dim_y / 2);
    sprint("3. Options\n");
    move_c(dim_x / 2 - 8, dim_y / 2 + 1);
    sprint("4. Controls\n");
    move_c(dim_x / 2 - 8, dim_y / 2 + 2);
    sprint("0. Exit\n\n");
}

// Music options
void setmusic(OPTION *O)
{
    unsigned short int sel;

    clear_s();

    move_c(0, dim_y / 2 - 2);
    if (O->mstate == OFF)
        sprint("Music OFF\n");
    else
        sprint("Music ON\n");

    sprint("1. Change\n");
    sprint("0. Exit\n\n");
    sprint("> ");
    scan("%hu", &sel);

    if (sel == 1)
    {
        move_c(0, dim_y / 2 - 2);
        if (O->mstate == OFF)
        {
            O->mstate = (MUSIC)1;
            sprint("Music On\n");
            init_music();
            sleep(1);
        }
        else
        {
            O->mstate = (MUSIC)0;
            sprint("Music OFF\n");
            exit_vlc();
        }
    }
    else if (sel == 0)
        return;

    else
    {
        move_c(0, dim_y / 2 + 2);
        sprint("Wrong selection, press enter to go back");
        setbuf(stdin, NULL);
        getchar();
    }
}

// Language options
void setlang(OPTION *O)
{
    unsigned short int sel;

    clear_s();

    move_c(0, dim_y / 2 - 2);

    if (O->lstate == ENGLISH)
        sprint("Set: English\n");

    else
        sprint("Set: Spanish\n");

    sprint("1. Change\n0. Exit\n\n");
    sprint("> ");
    scan("%hu", &sel);

    if (sel == 1)
    {

        move_c(0, dim_y / 2 - 2);
        if (O->lstate == ENGLISH)
        {
            O->lstate = (LANGUAGE)1;
            sprint("Selected: Spanish\n");
        }
        else
        {
            O->lstate = (LANGUAGE)0;
            sprint("Selected: English\n");
        }
    }
    else if (sel == 0)
        return;

    else
    {
        move_c(0, dim_y / 2 + 2);
        sprint("Wrong selection, press enter to go back");
        setbuf(stdin, NULL);
        getchar();
    }
}

// Options menu
void options()
{
    static unsigned short int sel;

    clear_s();
    move_c(0, dim_y / 2 - 2);
    sprint("1. Music\n2. Language\n0. Exit\n\n");
    sprint("> ");
    scan("%hu", &sel);

    if (sel == 1)
        setmusic(&O);

    else if (sel == 2)
        setlang(&O);

    else if (sel == 0)
        return;

    else
    {
        move_c(0, dim_y / 2 + 2);
        sprint("Wrong selection, press enter to select again");
        setbuf(stdin, NULL);
        getchar();
    }
    return options();
}

// Controls menu
void controls()
{
    clear_s();
    move_c(0, dim_y / 2 - 2);
    sprint("Controls:\n");
    sprint("ESC to exit game.\n");
    sprint("Use arrow keys to move your character\n");
    sprint("\nPress return to go back");
    setbuf(stdin, NULL);
    getchar();
}