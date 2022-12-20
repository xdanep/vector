#include "main.h"

void init_dir(); // create game files directory
unsigned short int LoadOptions(OPTION *O);
void SaveOptions(OPTION *O);
void SaveGame(PLAYER *P);
unsigned short int LoadGame(PLAYER *P);