#include "engine.h"
/*
 class intelligence : public tpool::Thread
 {
 void Entry();
 void smartbuttons(void);
 public:
 void go(void);
 void stop(void);
 };
*/

void intelligence::Entry(void)
{
    smartbuttons();
}

void intelligence::smartbuttons(void)
{
    int target;
    while (true)
    {
        sleep(1);
        
        { //up arrow
            target = env.location - (width + 1);
            if (target >= 0 && target < mapsize)
            {
                if (env.map[target] == '#')
                {
                    env.buttonstate.up = false;
                }
                else
                {
                    env.buttonstate.up = true;
                }
            }
            
            { //down arrow
                target = env.location + (width + 1);
                if (target >= 0 && target < mapsize)
                {
                    if (env.map[target] == '#')
                    {
                        env.buttonstate.down = false;
                    }
                    else
                    {
                        env.buttonstate.down = true;
                    }
                }
            }
            
            { //left arrow
                target = env.location - 1;
                if (target >= 0 && target < mapsize)
                {
                    if (env.map[target] == '#')
                    {
                        env.buttonstate.left = false;
                    }
                    else
                    {
                        env.buttonstate.left = true;
                    }
                }
            }
            
            { //right arrow
                target = env.location + 1;
                if (target >= 0 && target < mapsize)
                {
                    if (env.map[target] == '#')
                    {
                        env.buttonstate.right = false;
                    }
                    else
                    {
                        env.buttonstate.right = true;
                    }
                }
            }
        }
    }
    
}

void intelligence::go(void)
{
    Entry();
}

void intelligence::stop(void)
{
    Stop();
}