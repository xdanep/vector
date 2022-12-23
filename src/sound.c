/* sound.c -- API for song of vector */

//
// sound.c
// Vector
//
// Created by Aarch-64 on 21/12/2022
// Copyright (C) 2022 Agustín Gutíerrez. All rights reserved.
//

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

#include "include/sound.h"
#include "include/screen.h"

// Use for wav files
//   Mix_Chunk;
// Use for music files
//   Mix_Music;
Mix_Music *mod = NULL;
Mix_Chunk *wmod = NULL;

// Initialize SDL
void init_sdl(void)
{
    if (SDL_Init(SDL_INIT_AUDIO) < 0) 
        winerr("Failed to init SDL");
}

// Example: SelfControl.mp3 | 44100 | 1024
// standar for sound frequency: 44100
// standar for sound buffer len:  1024
void sound(void *sound, int sound_freq, int soundbufferlen)
{
    if (sound == NULL)
      winerr("Error in Sound Library (path music).");
    else if (sound_freq < 1)
      winerr("Error in Sound Library (sound freq).");
    else if (soundbufferlen < 1)
      winerr("Error in Sound Library (sound buffer len).");

    init_sdl();
    
    //Initialize SDL_mixer 
    if (Mix_OpenAudio(sound_freq, MIX_DEFAULT_FORMAT, 2, soundbufferlen) < 0)
        ar_winerr("sound init failed (SDL_mixer)", Mix_GetError());
       
    Mix_AllocateChannels(MAXCHAN);
    mod = Mix_LoadMUS(sound);
    if (mod == NULL)
      ar_winerr("Error in Sound Library (init music)", Mix_GetError());
    else
      Mix_PlayMusic(mod, -1); // mix, while reproduction */ -1 = always reproduction | 1 = one reproduction */
}

// Example: SelfControl.wav | 44100 | 1024
// standar for sound frequency: 44100
// standar for sound buffer len:  1024
void wsound(void *sound, int sound_freq, int soundbufferlen)
{
    if (sound == NULL)
      winerr("Error in Sound Library (path music)");
    else if (sound_freq < 1)
      winerr("Error in Sound Library (sound freq)");
    else if (soundbufferlen < 1)
      winerr("Error in Sound Library (sound buffer len)");
    
    init_sdl();
    
    //Initialize SDL_mixer 
    if (Mix_OpenAudio(sound_freq, MIX_DEFAULT_FORMAT, 2, soundbufferlen) < 0)
        ar_winerr("sound init failed (SDL_mixer)", Mix_GetError());
       
    Mix_AllocateChannels(MAXCHAN);
    wmod = Mix_LoadWAV(sound);
    if (wmod == NULL)
      ar_winerr("Error in Sound Library (init music)", Mix_GetError());
    else
      Mix_PlayChannel(-1, wmod, -1); // channel, mix, while reproduction */ -1 = always reproduction | 1 = one reproduction */
}

// Example: SelfControl.mp3
void stop_sound(void *sound)
{
    Mix_HaltMusic();
    Mix_FreeMusic(sound);
}

// Example: SelfControl.wav
void stop_wsound(void *sound)
{
    Mix_FreeChunk(sound);
}

void cleansound(void)
{
    Mix_CloseAudio();
    mod = NULL;
    wmod = NULL;
}

// Extras
void winerr(const char *text)
{
    WINDOW *winerr;
    winerr = newwin(3,42,(LINES-5)/2,(COLS-10)/2);
    
    if (text == NULL)
    {
        wmove(winerr, 1,2); // move in winerr window
        wprintw(winerr, "No data."); // print in winerr window
    }
    else
    {
        box(winerr, 0, 0); // draw a box in the screen
        box(stdscr, 0, 0); // draw a box in the main window
        curs_set(0); // remove cursor
        move(8,48); // move in main window
        printw("Win Error"); // print in main window
        mvwprintw(winerr, 1, 2, "%s", text); // print in winerr window
        refresh(); // refresh in main window
        wrefresh(winerr); // refresh in winerr window
        sleep(5); // sleep 5 seconds
        clear(); // clear windows
        curs_set(1); // add cursor
    }
}

void ar_winerr(const char *text, const char *ar)
{
    WINDOW *winerr;
    winerr = newwin(10,50,(LINES-5)/2,(COLS-45)/2);
    
    if (text == NULL)
    {
        wmove(winerr, 1,2); // move winerr window
        wprintw(winerr, "No data."); // print in winerr window
    }
    else
    {
        clear();
        box(winerr, 1, 1); // draw a box in the winerr window
        box(stdscr, ACS_VLINE,ACS_HLINE); // draw a box in the main window
        
        attron(A_BOLD);
        wattron(winerr,WA_BOLD);
        mvprintw((LINES-12)/2,(COLS-3)/2, "Win Error"); // print in main window
        mvwprintw(winerr, 2, 5, "%s\n\n%s", text, ar); // print in winerr window
        refresh(); // refresh main window
        wrefresh(winerr); // refresh winerr window
        attron(A_BLINK);
        attron(COLOR_PAIR(3));
        mvprintw(LINES-2, 2, "Enter any key for continue..."); // print in main window
        refresh(); // refresh in main window
        attroff(A_BOLD);
        attroff(A_BLINK);
        attroff(COLOR_PAIR(3));
        curs_set(0); // remove cursor
        getch(); // get char
        clear(); // clear windows
        delwin(winerr); // delete winerr window
    }
}
