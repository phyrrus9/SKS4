
#include "engine.h"

void nextlevel(void)
{
#define data env
    for (int i = 1, j = 0; i < mapsize; i++, j++)
    {
        int seed = rand() % 15 + 1;
        //printf("%i\n", seed);
        switch (seed)
        {
            case 1:
                data.map[i] = '#';
                break;
            case 2:
                data.map[i] = '&';
                data.kills_needed++;
                break;
            case 3:
                data.map[i] = '%';
                data.kills_needed++;
                break;
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
            case 9:
            case 10:
            case 11:
            case 12:
            case 13:
            case 14:
            case 15:
                data.map[i] = ' ';
                break;
            default:
                printf("err\n");
                break;
        }
        if (j == width + 1)
        {
            cout << "endl" << endl;
            data.map[i] = '\n';
            j = 0;
        }
        //printf("%c\n", data.map[i]);
    }
    data.map[data.location] = '@';
    data.kills_needed = 4;
#undef data
}