#pragma once
#include "building.h"

class Map;

class Church : public Building
{
  public:
    Church(int wN, int rN, int x, int y, Map& map);
    ~Church();
};
