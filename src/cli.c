#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "include/var.h"
#include "include/function.h"

void cli(int argc, char *argv[])
{
    (void)argc;

    VerSaveVar();

    if (argc==2)
    {
        if (!strcmp(argv[1], V.help)) // display help
        {
            printf("--version\t\t\tProgram version\n");
            exit(EXIT_SUCCESS);
        }
        else if (!strcmp(argv[1], V.version)) // display program version
        {
            printf("%s%s%s%s%s%s%s%s",V.namever,V.verver,V.coderver,V.builver,V.copyver,V.licever,V.typever,V.garaver);
            exit(EXIT_SUCCESS);
        }
    }
}