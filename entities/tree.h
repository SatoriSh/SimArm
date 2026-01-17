#pragma once
#include "naturalObjects.h"
#include <string>

class Map;

class Tree : public NaturalObjects
{
public:
    Tree(int health, int resourceAmount, std::string view, int x, int y, Map& map);
    ~Tree();
};
