#include <iostream>
#include "mountain.h"


Mountain::Mountain(int health, int resourceAmount, std::string view, int x, int y)
    : NaturalObjects(ResourceType::rock, health, resourceAmount, view, x, y)
{
}


Mountain::~Mountain() {}
