#include <stdio.h>
#include <stdlib.h>

#include "include/cli.h"
#include "include/files.h"
#include "include/game.h"
#include "include/main.h"
#include "include/menu.h"
#include "include/screen.h"
#include "include/vlc.h"

PLAYER P;
OPTION O;

int main(int argc, char *argv[])
{
    cli(argc, argv);

    unsigned short int select = 5, gst; // selector, game st

    init_option(&O);
    init_dir();
    gst = LoadOptions(&O);

    if (gst)
        lang_option(&O);

    start_s();

    do
    {
        clear_s(); // clear terminal
        menu();
        move_c(dim_x / 2 - 8, dim_y / 2 + 4);
        sprint("> ");
        scan("%hu", &select);

        if (select == 1)
        {
            ngame(&P);
            SaveGame(&P);

            if (O.mstate)
                exit_vlc();

            start();
            select = 5;
        }
        else if (select == 2)
        {
            gst = LoadGame(&P);

            if (gst)
            {
                if (O.mstate)
                    exit_vlc();

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

            move_c(dim_x / 2 - 8, dim_y / 2 + 4);
            sprint("Wrong selection, press enter to select again");
            setbuf(stdin, NULL);
            getchar();
        }
    } while (select > 4);

    exit_s();
    exit(EXIT_SUCCESS);
}