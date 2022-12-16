// 
// version.c
// vector
//
// Created by Aarch-64 on 8/12/2022
// Copyright © 2022 Aarch-64. All rights reserved.
//

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "include/var.h"
#include "include/function.h"

#define PROJECT_NAME "Vector"
#define PROJECT_VERSION "0.2.2"
#define CODER_NAME "Olympo"
#define ARCHITECTURE_BUILD "x86_64-pc-linux-gnu"
#define CONTRIBUTORS "Aarch-64 & xdanep"

VERSION V;

void VerSaveVar(void)
{

    FILE *verfile;
    char *user;
    unsigned short int i;

    strcpy(V.version, "--version");
    strcpy(V.help, "--help");
    //
    strcpy(V.namever, PROJECT_NAME);
    // //
    strcat(V.namever, " ");
    strcpy(V.verver, PROJECT_VERSION);
    // //
    strcat(V.verver, "(");
    strcpy(V.coderver, CODER_NAME);
    strcat(V.coderver, ")");
    strcat(V.coderver, "\n");
    //
    strcpy(V.builver, "This program was built for");
    strcat(V.builver, " ");
    strcat(V.builver, ARCHITECTURE_BUILD);
    strcat(V.builver, "\n");
    //
    strcpy(V.copyver, "Copyright (C) 2022-2022");
    strcat(V.copyver, " ");
    strcat(V.copyver, CONTRIBUTORS);
    strcat(V.copyver, ".");
    strcat(V.copyver, "\n");
    //
    strcpy(V.licever, "GPLv3+ License: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>");
    strcat(V.licever, "\n\n");
    //
    strcpy(V.typever, "This is free software: anyone is free to redistribute and modify it.");
    strcat(V.typever, "\n");
    //
    strcpy(V.garaver, "There is no WARRANTY, up to the limits permitted by applicable laws.");
    strcat(V.garaver, "\n");
    //

    strcpy(dir, "/home/");

    i = strlen(getlogin());
    user = malloc(i);

    if (user == NULL)
    {
        printf("Cannot allocate dynamic memory");
        free(user);
        exit(EXIT_FAILURE);
    }

    strcpy(user, getlogin());
    strcat(dir, user);

    strcat(dir, "/.vector/version.txt");

    if((verfile = fopen(dir,"w")) == NULL)
    {
        printf("File can't be opened\n");
        return;
    }
    else
    {
        fputs("PROJECT NAME: ", verfile);
        fputs(PROJECT_NAME, verfile);
        fputs("\nCODER NAME: ", verfile);
        fputs(CODER_NAME, verfile);
        fputs("\nVERSION: ", verfile);
        fputs(PROJECT_VERSION, verfile);
        fputs("\nARCHITECTURE: ",verfile);
        fputs(ARCHITECTURE_BUILD, verfile);
        fputs("\nCONTRIBUTORS: ", verfile);
        fputs(CONTRIBUTORS, verfile);
    }

    fclose(verfile);
}
