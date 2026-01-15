#include "mountain.h"
#include "../map.h"

Mountain::Mountain(int health, int resourceAmount, std::string view, int x, int y, Map& map)
    : NaturalObjects(ResourceType::Rock, health, resourceAmount, view, x, y, map)
{
}

Mountain::~Mountain() {}
