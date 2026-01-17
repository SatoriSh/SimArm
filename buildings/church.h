#pragma once
#include "building.h"

class Map;

class Church : public Building
{
    Church(int wN, int rN, int x, int y, Map& map);
    ~Church();
};
