
#include "engine.h"
#define casechar(a) if (env.map[location] == a)
void attack(int location)
{
    int attack = env.levels_completed * env.userdata.kills + env.userdata.totalkills + env.userdata.health * 2;
    int strength = location / 3 - env.kills_needed;
    int power = 0;
    casechar('%')
        strength += (strength / 3);
    casechar('&')
        strength += (strength / 2);
    power = attack - strength;
    cout << attack << "::" << strength << "::" << power << endl;
    if (power > 0)
    {
        env.userdata.health -= power;
        destroy(location);
    }
}

void destroy(int location)
{
    if (location > 0 && env.map[location] != '#' && env.map[location] != '\n')
    {
        env.map[location] = ' ';
        env.userdata.kills++;
        env.userdata.totalkills++;
        env.userdata.score++;
        casechar('%')
            env.userdata.score++;
        casechar('&')
            env.userdata.score += 2;
        env.needs_display = true;
    }
}
#undef casechar(a)