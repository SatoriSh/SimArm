#include "mountain.h"
#include <iostream>

Mountain::Mountain(int health, int resourceAmount, std::string view, int x, int y)
    : NaturalObjects(ResourceType::Rock, health, resourceAmount, view, x, y)
{
}

Mountain::~Mountain() {}
