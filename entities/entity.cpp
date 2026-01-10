#include <iostream>
#include "entity.h"
#include "../map.h"
#include "../utils/utils.h"

Entity::Entity(int h, int d, std::string v, int x, int y)
    : health(h), damage(d), view(v), x(x), y(y) // ну и синтаксис блять
{
};

void Entity::move(const Map& map)
{
    int direction = Utils::getRandomInt(1, 4); // 1 - up, 2 - right, 3 - down, 4 - left

    //int direction = 2;

    if (direction == 1 && map.canMove(x, y - 1))
        setPosition(x, y - 1);
    else if (direction == 2 && map.canMove(x + 1, y))
        setPosition(x + 1, y);
    else if (direction == 3 && map.canMove(x, y + 1))
        setPosition(x, y + 1);
    else if (direction == 4 && map.canMove(x - 1, y))
        setPosition(x - 1, y);
}

void Entity::setPosition(int x, int y)
{
    this->x = x;
    this->y = y;
}

Entity::~Entity() {};
