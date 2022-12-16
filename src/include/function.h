#include "var.h"

void cli(int argc, char *argv[]);   // CLI arguments
void VerSaveVar();                  // CLI arguments
void init_option(OPTION *O);        // initialize options
void menu();                        // display menu
void setmusic(OPTION *O);           // music options
void setlang(OPTION *O);            // language options
void options();
void controls();
void ngame(PLAYER *P);              // start new game
void start();                       // start game
void init_dir();                    // create game files directory
void LoadOptions(OPTION *O);
void SaveOptions(OPTION *O);
void SaveGame(PLAYER *P);
unsigned short int LoadGame(PLAYER *P);

// for music
void init_music();
void game_music();
void exit_vlc();