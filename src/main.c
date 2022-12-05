/*
Project: Vector
Started: 28/09/2022
Days coding: 6
Author: Xdan
Collaborators: similCode
Version: 0.1.2
*/

#include <stdio.h>
#include <stdlib.h>
#include "var.h"
#include "function.h"

PLAYER P;
OPTION O;

char dir[200];
char dir2[200];

int main()
{
    unsigned short int select = 5, gst;

    init_option(&O);
    init_dir();
    LoadOptions(&O);

    do
    {
        system("clear");//activate for linux
        //system("CLS");//activate for windows
        printf("Welcome to Vector\n\n");//Replace X by the name of the game
        menu();
        printf("::");
        scanf("%hu", &select);

        if(select == 1)
        {
            ngame(&P);
            SaveGame(&P); 
            start();
            select = 5;
        }
        else if(select == 2)
        {
            gst = LoadGame(&P);

            if(gst)
            {
                start();
                select = 5;
            }
            else
            {
                select = 5;
                continue;
            }
        }

        else if(select == 3)
        {
            options();
            SaveOptions(&O);
            select = 5;
        }

        else if(select == 0)
        continue;

        else
        {
            printf("Wrong selection, press enter to select again");
            setbuf (stdin, NULL);
            getchar();
        }
    }while(select > 3);

    exit(EXIT_SUCCESS);
}