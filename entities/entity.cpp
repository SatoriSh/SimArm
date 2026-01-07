#include <iostream>
#include "entity.h"
#include "../map.h"

Entity::Entity(int h, int d, std::string v, int x, int y)
    : health(h), damage(d), view(v), x(x), y(y) // ну и синтаксис блять
{
};

bool Entity::checkCollisions() const
{
    
}

void Entity::move()
{
    
}

void Entity::setPosition(int x, int y)
{
    this->x = x;
    this->y = y;
}

Entity::~Entity() {};
