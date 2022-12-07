#include "var.h"

void cmd(int argc, char *argv[]);
void init_option(OPTION *O);
void menu();
void setmusic(OPTION *O);
void setlang(OPTION *O);
void options();
void controls();
void ngame(PLAYER *P);
void start();
void init_dir();
void LoadOptions(OPTION *O);
void SaveOptions(OPTION *O);
void SaveGame(PLAYER *P);
unsigned short int LoadGame(PLAYER *P);