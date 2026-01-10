#include <iostream>
#include "mountain.h"


mountain::mountain(int health, int resourceAmount, std::string view)
    : naturalObjects(ResourceType::rock,health, resourceAmount, view)
{
}


mountain::~mountain() {}
