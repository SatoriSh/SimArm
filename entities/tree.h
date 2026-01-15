#pragma once
#include "naturalObjects.h"
#include <iostream>

class Map;

class Tree : public NaturalObjects
{
public:
    Tree(int health, int resourceAmount, std::string view, int x, int y, Map& map);
    ~Tree();
};
