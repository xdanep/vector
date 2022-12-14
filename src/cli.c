#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "var.h"
#include "function.h"

void cli(int argc, char *argv[])
{
    if (argv[1] == NULL) // run program
    {
        ;
    }
    else if (!strcmp(argv[1], "--help")) // display help
    {
        printf("--version\t\t\tProgram version\n");
        exit(EXIT_SUCCESS);
    }
    else if (!strcmp(argv[1], "--version")) // display program version
    {
        printf("version 0.1.4\n");
        exit(EXIT_SUCCESS);
    }
    else //exiting program for invalid argument
    {
        printf("Invalid argument\n");
        exit(EXIT_SUCCESS);
    }
}