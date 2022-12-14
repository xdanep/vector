/* sound.h --  header library for sound.c */

#ifndef SOUND_H_
#define SOUND_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <stdbool.h>
#include <string.h>
#include <syslog.h>

// #define SONG1 "SelfControl.mp3"
// #define SONG2 "Vitality_-_Electro_Shock_Sport_Dance.ogg"

#define SONG1 "menusound.xm"
#define SONG2 "gamesound.mp3"
#define SONG3 "gameover.wav"

#define MAXCHAN 32
#define SOUNDFREQ 44100
#define SOUNDBUFLEN 2048    
                
extern char out_sound_dir[70];
extern char music_ini[70];
extern char music_game[70];
extern char music_game_over[70];     

extern bool nosound;
                 
            //       music.mp3, 44100, 1024
void sound(void *sound, int sound_freq, int soundbufferlen); // sound(SONG1, SOUNDFREQ, SOUNDBUFFLEN);
void wsound(void *sound, int sound_freq, int soundbufferlen);
void stop_sound(void *sound); // stop_sound(SONG1);
void stop_wsound(void *sound); // stop_sound(WAV1);
void cleansound();

// Extras
void winerr(const char *text);
void ar_winerr(const char *text, const char *ar);

#endif // SOUND_H_
