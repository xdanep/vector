#include "var.h"
#include "function.h"
#include <stdio.h>
#include <stdlib.h>

void init_option(OPTION*O)
{
    O->lstate = (LANGUAGE)0;
    O->mstate = (MUSIC)1;
}

void menu()//main menu
{
    printf("1. Start new game\n");
    printf("2. Load game\n");
    printf("3. Options\n");
    printf("4. Controls\n");
    printf("0. Exit\n");
}

void setmusic(OPTION*O)//set music
{
    unsigned short int sel;

    system("clear");//activate for linux
    //system("CLS");//activate for windows

    if(O->mstate == OFF)
    printf("Music OFF\n");
    else
    printf("Music ON\n");

    printf("1. Change\n0. Exit\n");
    printf(">");
    scanf("%hu", &sel);

    if(sel == 1)
    {
        if(O->mstate == OFF)
        {
            O->mstate = (MUSIC)1;
            printf("Music On\n");
        }
        else
        {
            O->mstate = (MUSIC)0;
            printf("Music OFF\n");
        }
    }
    else if(sel == 0)
    return;

    else
    {
        printf("Wrong selection, press enter to go back");
        setbuf (stdin, NULL);
        getchar();
    }
}

void setlang(OPTION*O)//set language
{
    unsigned short int sel;

    system("clear");//activate for linux
    //system("CLS");//activate for windows

    if(O->lstate == ENGLISH)
    printf("Set: English\n");

    else
    printf("Set: Spanish\n");

    printf("1. Change\n0. Exit\n");
    printf(">");
    scanf("%hu", &sel);

    if(sel == 1)
    {
        if(O->lstate == ENGLISH)
        {
            O->lstate = (LANGUAGE)1;
            printf("Selected: Spanish\n");
        }
        else
        {
            O->lstate = (LANGUAGE)0;
            printf("Selected: English\n");
        }
    }
    else if(sel == 0)
    return;

    else
    {
        printf("Wrong selection, press enter to go back");
        setbuf (stdin, NULL);
        getchar();
    }
}

void options()
{
    static unsigned short int sel;

    system("clear");//activate for linux
    //system("CLS");//activate for windows

    printf("1. Music\n2. Language\n0. Exit\n");
    printf(">");
    scanf("%hu", &sel);

    if(sel == 1)
    setmusic(&O);

    else if(sel == 2)
    setlang(&O);

    else if(sel == 0)
    return;

    else
    {
        printf("Wrong selection, press enter to select again");
        setbuf(stdin, NULL);
        getchar();
    }
    return options();
}

void controls()
{
    system("clear");
    printf("Controls:\n");
    printf("ESC to exit game.\n");
    printf("Use arrow keys to move your character\n");
    printf("\nPress return to go back");
    setbuf(stdin, NULL);
    getchar();
}