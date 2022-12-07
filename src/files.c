#include "var.h"
#include "function.h"
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>

void init_dir()
{
    errno = 0;
    char *user;
    unsigned short int i;

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

    strcat(dir, "/.vector/");

    if (mkdir(dir, S_IRWXU | S_IRWXG | S_IRWXO) == -1) // game files folder
    {
        if (errno != EEXIST)
        {
            printf("Error: %s, enter to exit\n", strerror(errno));
            getchar();
        }
    }

    strcpy(dir2, dir);
    strcat(dir2, "conf/");

    if (mkdir(dir2, S_IRWXU | S_IRWXG | S_IRWXO) == -1) // game configurations folder
    {
        if (errno != EEXIST)
        {
            printf("Error: %s, enter to exit\n", strerror(errno));
            getchar();
        }
    }

    free(user);
}

void LoadOptions(OPTION *O)
{
    FILE *fPtr;
    char dirl[200];

    strcpy(dirl, dir2);
    strcat(dirl, "options.bin");

    if ((fPtr = fopen(dirl, "rb")) == NULL)
        return;

    else
        fread(O, sizeof(OPTION), 1, fPtr);

    fclose(fPtr);
}

void SaveOptions(OPTION *O)
{
    FILE *fPtr;
    char dirl[200];

    strcpy(dirl, dir2);
    strcat(dirl, "options.bin");

    if ((fPtr = fopen(dirl, "wb")) == NULL)
    {
        printf("Error, cannot save\n");
        return;
    }

    else
        fwrite(O, sizeof(OPTION), 1, fPtr);

    fclose(fPtr);
}

void SaveGame(PLAYER *P)
{
    FILE *fPtr;
    char dirl[200];

    strcpy(dirl, dir);
    strcat(dirl, "save.bin");

    if ((fPtr = fopen(dirl, "wb")) == NULL)
    {
        printf("Error, cannot save\n");
        return;
    }

    else
        fwrite(P, sizeof(PLAYER), 1, fPtr);

    fclose(fPtr);
}

unsigned short int LoadGame(PLAYER *P)
{
    FILE *fPtr;
    char dirl[200];

    strcpy(dirl, dir);
    strcat(dirl, "save.bin");

    if ((fPtr = fopen(dirl, "rb")) == NULL)
    {
        printf("No data saved, press enter to continue\n");
        setbuf(stdin, NULL);
        getchar();
        return 0;
    }
    else
        fread(P, sizeof(PLAYER), 1, fPtr);

    fclose(fPtr);
    return 1;
}