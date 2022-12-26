//
// cmd.c
// Vector
//
// Created by Aarch-64 on 18/12/2022.
// Copyright (C) 2022 Agustín Gutíerrez. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "include/cmd.h"

/* READ ONLY VAR */
const char *const vector_copyright = ("Copyright (C) 2022 Agustín Gutíerrez, Xdanep.");
const char *const vector_license = ("License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>\n");

const char *const tt = PROJNAME;
const char *const dist_version = DISTVERSION;
const int build_version = BUILDVERSION;
const char *const release_status = RELSTATUS;
const char *const build_platform = BUILDPTFORM;

const char *const argv_version = ARGV1;
const char *const argv_help = ARGV2;
const char *const argv_ver = ARGV3;
const char *const argv_hel = ARGV4;

/* PRINT (xxxxx, version x.x.x(x)-xxxxx (xxxxxxxxxxx)) */
void show_vector_version(void)
{
    printf("%s, version %s(%d)-%s (%s)\n", tt, dist_version, build_version, release_status, build_platform);
}

/* PRINT EXTRA INFO */
void extended(void)
{
    printf("%s\n", (vector_copyright));
    printf("%s\n", (vector_license));
    printf("%s\n", ("This is free software; you are free to change and redistribute it."));
    printf("%s\n", ("There is NO WARRANTY, to the extent permitted by law."));
}

/* CLI arguments */
void cmd(int argc, char *argv[])
{
    if (argc == 2)
    { 
        /* if (argument cmd 1) == argv_help */
        if (!strcmp(argv[1], argv_help) || !strcmp(argv[1], argv_hel)) // || if (argument cmd 1) == argv_hel...
        { 
            printf("--version\t\t\tProgram version\n");
            exit(EXIT_SUCCESS);
        } 
        
        /* else if (argument cmd 1) == argv_version */
        else if (!strcmp(argv[1], argv_version) || !strcmp(argv[1], argv_ver)) // || if (argument cmd 1) == argv_hel...
        { 
            show_vector_version();
            extended();
            exit(EXIT_SUCCESS);
        }
    }
}