#include "entity.h"
#include "../map.h"
#include "../utils/utils.h"

Entity::Entity(int h, int d, std::string v, int x, int y, Map& m)
    : health(h), damage(d), view(v), x(x), y(y), map(m) // ну и синтаксис блять
{
};

void Entity::move()
{
    for (int i = 0; i < 4; i++)
    {
        int direction = Utils::getRandomInt(1, 4); // 1 - up, 2 - right, 3 - down, 4 - left

        if (direction == 1 && map.canMove(x, y - 1))
        {
            setPosition(x, y - 1);
            break;
        }
        else if (direction == 2 && map.canMove(x + 1, y))
        {
            setPosition(x + 1, y);
            break;
        }
        else if (direction == 3 && map.canMove(x, y + 1))
        {
            setPosition(x, y + 1);
            break;
        }
        else if (direction == 4 && map.canMove(x - 1, y))
        {
            setPosition(x - 1, y);
            break;
        }
    }
}

void Entity::setPosition(int x, int y)
{
    this->x = x;
    this->y = y;
}

Entity::~Entity() {};
