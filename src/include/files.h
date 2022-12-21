#include "main.h"

extern char dir[100];
// extern char dir2[100];

void init_dir();
unsigned short int LoadOptions(OPTION *O);
void SaveOptions(OPTION *O);
void SaveGame(PLAYER *P);
unsigned short int LoadGame(PLAYER *P);
void saveScore(PLAYER P, int score);