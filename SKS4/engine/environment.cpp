//
//  environment.cpp
//  SKS4
//
//  Created by Ethan Laur on 8/28/12.
//  Copyright (c) 2012 Ethan Laur. All rights reserved.
//

#include "environment.h"
/*
 void init(void);
 char map[900];
 char grid[900];
 char * view;
 int location;
 int health;
 int levels_completed;
*/

void environment_init(_environment_data &data)
{
    data.location = 0;
    data.needs_display = true;
    data.time = 3600;
    data.buttonstate.up = false;
    data.buttonstate.down = false;
    data.buttonstate.left = false;
    data.buttonstate.right = false;
    data.buttonstate.save = false;
    data.buttonstate.restore = false;
    data.buttonstate.attack = false;
    data.allow_refresh = true;
    data.game_over = false;
    data.userdata.health = 100;
    data.userdata.score = 0;
    data.userdata.kills = 0;
    data.userdata.totalkills = 0;
    nextlevel();
}