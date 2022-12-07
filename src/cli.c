#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "var.h"
#include "function.h"

void cmd(int argc, char *argv[])
{
    if (argv[1] == NULL)
    {
        ;
    }
    else if (!strcmp(argv[1], "--help"))
    {
        printf("--version\t\t\tProgram version\n");
        exit(EXIT_SUCCESS);
    }
    else if (!strcmp(argv[1], "--version"))
    {
        printf("version 0.1.4\n");
        exit(EXIT_SUCCESS);
    }
    else
    {
        printf("Invalid argument\n");
        exit(EXIT_SUCCESS);
    }
}