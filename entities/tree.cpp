#include "tree.h"
#include "../map.h"

Tree::Tree(int health, int resourceAmount, std::string view, int x, int y, Map& map)
    : NaturalObjects(ResourceType::Wood, health, resourceAmount, view, x, y, map)
{

}

Tree::~Tree() {};
