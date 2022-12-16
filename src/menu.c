#include "include/var.h"
#include "include/function.h"
#include "include/screen.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void init_option(OPTION *O)
{
    O->lstate = (LANGUAGE)0;
    O->mstate = (MUSIC)1;
}

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

void menu() // main menu
{
    move_c(dim_x / 2 - 8, dim_y / 2 - 2);
    print("1. Start new game\n");
    move_c(dim_x / 2 - 8, dim_y / 2 - 1);
    print("2. Load game\n");
    move_c(dim_x / 2 - 8, dim_y / 2);
    print("3. Options\n");
    move_c(dim_x / 2 - 8, dim_y / 2 + 1);
    print("4. Controls\n");
    move_c(dim_x / 2 - 8, dim_y / 2 + 2);
    print("0. Exit\n\n");
}

void setmusic(OPTION *O)
{
    unsigned short int sel;

    clear_s();

    move_c(0, dim_y / 2 - 2);
    if (O->mstate == OFF)
        print("Music OFF\n");
    else
        print("Music ON\n");

    print("1. Change\n");
    print("0. Exit\n\n");
    print("> ");
    scan("%hu", &sel);

    if (sel == 1)
    {
        move_c(0, dim_y / 2 - 2);
        if (O->mstate == OFF)
        {
            O->mstate = (MUSIC)1;
            print("Music On\n");
            init_music();
            sleep(1);
        }
        else
        {
            O->mstate = (MUSIC)0;
            print("Music OFF\n");
            exit_vlc();
        }
    }
    else if (sel == 0)
        return;

    else
    {
        move_c(0, dim_y / 2 + 2);
        print("Wrong selection, press enter to go back");
        setbuf(stdin, NULL);
        getchar();
    }
}

void setlang(OPTION *O)
{
    unsigned short int sel;

    clear_s();

    move_c(0, dim_y / 2 - 2);

    if (O->lstate == ENGLISH)
        print("Set: English\n");

    else
        print("Set: Spanish\n");

    print("1. Change\n0. Exit\n\n");
    print("> ");
    scan("%hu", &sel);

    if (sel == 1)
    {

        move_c(0, dim_y / 2 - 2);
        if (O->lstate == ENGLISH)
        {
            O->lstate = (LANGUAGE)1;
            print("Selected: Spanish\n");
        }
        else
        {
            O->lstate = (LANGUAGE)0;
            print("Selected: English\n");
        }
    }
    else if (sel == 0)
        return;

    else
    {
        move_c(0, dim_y / 2 + 2);
        print("Wrong selection, press enter to go back");
        setbuf(stdin, NULL);
        getchar();
    }
}

void options()
{
    static unsigned short int sel;

    clear_s();
    move_c(0, dim_y / 2 - 2);
    print("1. Music\n2. Language\n0. Exit\n\n");
    print("> ");
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
        print("Wrong selection, press enter to select again");
        setbuf(stdin, NULL);
        getchar();
    }
    return options();
}

void controls()
{
    clear_s();
    move_c(0, dim_y / 2 - 2);
    print("Controls:\n");
    print("ESC to exit game.\n");
    print("Use arrow keys to move your character\n");
    print("\nPress return to go back");
    setbuf(stdin, NULL);
    getchar();
}