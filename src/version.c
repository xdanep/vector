// 
// version.c
// vector
//
// Created by Aarch-64 on 8/12/2022
// Copyright © 2022 Aarch-64. All rights reserved.
//

#include <string.h>
#include <stdio.h>

#include "include/var.h"
#include "include/function.h"

#define PROYECT_NAME "Vector"
#define PROYECT_VERSION "0.2.1"
#define CODER_NAME "Olympo"
#define ARQUITECTURE_BUILD "x86_64-pc-linux-gnu"
#define CONTRIBUTORS "Aarch-64 & xdanep"

VERSION V;

FILE *verfile;

void VerSaveVar(void)
{
    strcpy(V.version, "--version");
    strcpy(V.help, "--help");
    //
    strcpy(V.namever, PROYECT_NAME);
    // //
    strcat(V.namever, " ");
    strcpy(V.verver, PROYECT_VERSION);
    // //
    strcat(V.verver, "(");
    strcpy(V.coderver, CODER_NAME);
    strcat(V.coderver, ")");
    strcat(V.coderver, "\n");
    //
    strcpy(V.builver, "This program was built for");
    strcat(V.builver, " ");
    strcat(V.builver, ARQUITECTURE_BUILD);
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
    
    verfile=fopen("version.txt","w");
    
    fputs("PROYECT NAME: ", verfile);
    fputs(PROYECT_NAME, verfile);
    fputs("\nCODER NAME: ", verfile);
    fputs(CODER_NAME, verfile);
    fputs("\nVERSION: ", verfile);
    fputs(PROYECT_VERSION, verfile);
    fputs("\nARQUITECTURE: ",verfile);
    fputs(ARQUITECTURE_BUILD, verfile);
    fputs("\nCONTRIBUTORS: ", verfile);
    fputs(CONTRIBUTORS, verfile);

    fclose(verfile);
}
