#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>

#include "include/screen.h"
#include "include/files.h"
#include "include/vlc.h"

void init_dir()
{
    errno = 0;
    char *user;
    unsigned short int i;

    // creating main directory
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

    if (strlen(user) < 65)
        strcat(dir, user);
    else
    {
        printf("Invalid user, for security reasons the program \
        will exit");
        exit(EXIT_FAILURE);
    }

    free(user);

    strcat(dir,"/.config/");
    strcat(dir, "vector/");

    if (mkdir(dir, S_IRWXU | S_IRWXG | S_IRWXO) == -1) // game files folder
    {
        if (errno != EEXIST)
        {
            printf("Error: %s, enter to exit\n", strerror(errno));
            getchar();
        }
    }
    /*
    // creating configurations directory
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
    */
}

unsigned short int LoadOptions(OPTION *O)
{
    FILE *fPtr;
    char dirl[200];

    strcpy(dirl, dir);
    strcat(dirl, "options.bin");

    if ((fPtr = fopen(dirl, "rb")) == NULL)
        return 1;

    else
        fread(O, sizeof(OPTION), 1, fPtr);

    fclose(fPtr);

    if (O->mstate)
    {
        init_music();
        sleep(1);
    }
    return 0;
}

void SaveOptions(OPTION *O)
{
    FILE *fPtr;
    char dirl[200];

    strcpy(dirl, dir);
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
        move_c(dim_x / 2 - 8, dim_y / 2 + 4);
        sprint("No data saved, press enter to continue\n");
        setbuf(stdin, NULL);
        getchar();
        return 0;
    }
    else
        fread(P, sizeof(PLAYER), 1, fPtr);

    fclose(fPtr);
    return 1;
}