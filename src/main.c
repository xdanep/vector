// Version: 0.1.4

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "var.h"
#include "function.h"

PLAYER P;
OPTION O;

char dir[200];
char dir2[200];

int main(int argc, char *argv[])
{
    cmd(argc, argv);
    unsigned short int select = 5, gst; //selector, game state
                                    
    init_option(&O);
    init_dir();
    LoadOptions(&O);

    do
    {
        system("clear");    // clear terminal
        printf("Welcome to Vector\n\n"); 
        menu();
        printf("> ");
        scanf("%hu", &select);

        if (select == 1)
        {
            ngame(&P);
            SaveGame(&P);
            start();
            select = 5;
        }
        else if (select == 2)
        {
            gst = LoadGame(&P);

            if (gst)
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

        else if (select == 3)
        {
            options();
            SaveOptions(&O);
            select = 5;
        }

        else if (select == 4)
        {
            controls();
            select = 5;
        }

        else if (select == 0)
            continue;

        else
        {
            printf("Wrong selection, press enter to select again");
            setbuf(stdin, NULL);
            getchar();
        }
    } while (select > 4);

    exit(EXIT_SUCCESS);
}