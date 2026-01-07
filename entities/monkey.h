#pragma once
#include "entity.h"
#include <vector>

class Monkey : public Entity
{
public:
    Monkey(int health, int damage, std::string view, int x, int y);
};
