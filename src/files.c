#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>

#include "include/screen.h"
#include "include/files.h"
#include "include/vlc.h"

// Create game files directory
void init_dir()
{
    errno = 0;
    char *user;
    unsigned short int i;

    // creating main directory
    strcpy(dir, "/home/");

    i = strlen(getlogin()); // Return the login name of the user.
    user = malloc(i);       // allocating memory

    if (user == NULL)       // verifying memory
    {
        printf("Cannot allocate dynamic memory");
        
        free(user);

        exit(EXIT_FAILURE);
    }

    strcpy(user, getlogin());   // saving login name

    if (strlen(user) < 63)      // verifying user lenght
    strcat(dir, user);

    else
    {
        printf("Invalid user, for security reasons the program will exit");

        exit(EXIT_FAILURE);
    }

    free(user);                 // Free allocated memory

    strcat(dir,"/.config/");
    strcat(dir, "vector/");

    if (mkdir(dir, S_IRWXU | S_IRWXG | S_IRWXO) == -1) // game files folder
    {
        if (errno != EEXIST)
        {
            printf("Error: %s, enter to exit\n", strerror(errno));

            setbuf(stdin, NULL);
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
            setbuf(stdin, NULL);
            getchar();
        }
    }
    */
}

// Load game options
unsigned short int LoadOptions(OPTION *O)
{
    FILE *fPtr;
    char dirl[100];

    strcpy(dirl, dir);
    strcat(dirl, "options.bin");

    // loading options
    if ((fPtr = fopen(dirl, "rb")) == NULL) // opening options file in reading mode
        return 1;

    else
        fread(O, sizeof(OPTION), 1, fPtr);  // reading OPTION structure

    fclose(fPtr);                           // closing options file

    if (O->mstate)                          // music initializator
    {
        init_music();
    }

    return 0;
}

// Save game options
void SaveOptions(OPTION *O)
{
    FILE *fPtr;
    char dirl[100];

    strcpy(dirl, dir);
    strcat(dirl, "options.bin");

    // saving options
    if ((fPtr = fopen(dirl, "wb")) == NULL) // opening options file in writing mode
    {
        printf("Error, cannot save\n");
        return;
    }

    else
        fwrite(O, sizeof(OPTION), 1, fPtr); // writing OPTION structure

    fclose(fPtr);                           // closing options file
}

// Save game
void SaveGame(PLAYER *P)
{
    FILE *fPtr;
    char dirl[100];

    strcpy(dirl, dir);
    strcat(dirl, "save.bin");

    // saving game
    if ((fPtr = fopen(dirl, "wb")) == NULL) // opening save file in writing mode
    {
        printf("Error, cannot save\n");
        return;
    }

    else
        fwrite(P, sizeof(PLAYER), 1, fPtr); // writing PLAYER structure

    fclose(fPtr);                           // closing save file
}

// Load game
unsigned short int LoadGame(PLAYER *P)
{
    FILE *fPtr;
    char dirl[100];

    strcpy(dirl, dir);
    strcat(dirl, "save.bin");

    // loading game
    if ((fPtr = fopen(dirl, "rb")) == NULL) // opening save file in reading mode
    {
        move_c(dim_x / 2 - 8, dim_y / 2 + 4);   // moving pinter
        sprint("No data saved, press enter to continue\n");

        setbuf(stdin, NULL);                // cleaning buffer
        getchar();                          // enter to return

        return 0;
    }
    else
        fread(P, sizeof(PLAYER), 1, fPtr);  // reading PLAYER structure

    fclose(fPtr);                           // closing save file

    return 1;
}

void saveScore(PLAYER P, int score)
{
    FILE *fPtr;
    char dirl[100];

    strcpy(dirl, dir);
    strcat(dirl, "score.txt");

    // loading game
    if ((fPtr = fopen(dirl, "a")) == NULL) // opening save file in appending mode
    {
        return;
    }
    else
        fprintf(fPtr, "%s score: %d\n", P.name, score);  // reading PLAYER structure

    fclose(fPtr);                           // closing save file
}