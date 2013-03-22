//
//  environment.h
//  SKS4
//
//  Created by Ethan Laur on 8/28/12.
//  Copyright (c) 2012 Ethan Laur. All rights reserved.
//

#include "engine.h"

#ifndef __SKS4__environment__
#define __SKS4__environment__
#include <cstdlib>
#include <cstring>
#include <stdio.h>
#include <iostream>
using namespace std;

struct _userdata
{
    int score;
    int kills;
    int totalkills;
    int health;
};

struct _buttonstate
{
    bool up, down, left, right;
    bool save, restore;
    bool attack;
};

struct _environment_data
{
    char map[mapsize + 5];
    char grid[mapsize + 5];
    char * view;
    int location;
    int kills_needed;
    int levels_completed;
    double time;
    bool allow_refresh;
    bool needs_display;
    bool game_over;
    _buttonstate buttonstate;
    _userdata userdata;
};

void environment_init(_environment_data &);

#endif /* defined(__SKS4__environment__) */
