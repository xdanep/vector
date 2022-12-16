// 
// vlc.c
// Vector
//
// Created by Aarch-64 on 10/12/2022
// Copyright © 2022 Aarch-64. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vlc/vlc.h>
#include "include/function.h"
#include "include/var.h"

libvlc_instance_t *inst;
libvlc_media_player_t *mp;
libvlc_media_t *m;

void init_music(void)
{  
    // load the vlc engine
    inst = libvlc_new(0, NULL);

    // create a new item
    m = libvlc_media_new_path(inst, ini_music);

    init_vlc();
}

void game_music(void)
{  
    // load the vlc engine
    inst = libvlc_new(0, NULL);

    // create a new item
    m = libvlc_media_new_path(inst, g_music);
    
    init_vlc();
}


void exit_vlc(void)
{
    // stop playing
    libvlc_media_player_stop(mp);

    // free the media_player
    libvlc_media_player_release(mp);
    
    libvlc_release(inst);
}
