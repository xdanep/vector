//
// vlc.c
// Vector
//
// Created by Aarch-64 on 10/12/2022
//

#include <vlc/vlc.h>

#include "include/vlc.h"

libvlc_instance_t *inst;
libvlc_media_player_t *mp;
libvlc_media_t *m;

// Initialize VLC
void init_vlc(void)
{
    // create a media play playing environment
    mp = libvlc_media_player_new_from_media(m);

    // no need to keep the media now
    libvlc_media_release(m);

    // play the media_player
    libvlc_media_player_play(mp);
}

// Intialize main music
void init_music(void)
{
    // load the vlc engine
    inst = libvlc_new(0, NULL);

    // create a new item
    m = libvlc_media_new_path(inst, SONG1);

    init_vlc();
}

// Initialize game music
void game_music(void)
{
    // load the vlc engine
    inst = libvlc_new(0, NULL);

    // create a new item
    m = libvlc_media_new_path(inst, SONG2);

    init_vlc();
}

// Exit VLC
void exit_vlc(void)
{
    // stop playing
    libvlc_media_player_stop(mp);

    // free the media_player
    libvlc_media_player_release(mp);

    libvlc_release(inst);
}