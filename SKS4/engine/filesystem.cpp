#include "engine.h"

void save(_environment_data &data)
{
    ofstream f("save.sks4", ios::binary | ios::trunc);
    f.write(reinterpret_cast<char *>(&data), sizeof(_environment_data));
    f.close();
}

void restore(_environment_data &data)
{
    ifstream f("save.sks4", ios::binary);
    f.read(reinterpret_cast<char *>(&data), sizeof(_environment_data));
    f.close();
}