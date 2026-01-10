#include "tree.h"


Tree::Tree(int health, int resourceAmount, std::string view, int x, int y)
    : NaturalObjects(ResourceType::Wood, health, resourceAmount, view, x, y)
{
}

Tree::~Tree() {};
