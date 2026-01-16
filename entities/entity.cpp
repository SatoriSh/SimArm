#include "entity.h"
#include "../map.h"

Entity::Entity(int h, int d, std::string v, int x, int y, Map& m)
    : health(h), damage(d), view(v), x(x), y(y), map(m) // ну и синтаксис блять
{
    changeDirection();
};

void Entity::move()
{
    if (movingCount >= moveCountInOneDirection)
    {
        movingCount = 0;
        changeDirection();
    }
    isMoveInCurrentTick = false;

    for (int i = 0; i < 4; i++)
    {
        if (direction == 1 && map.canMove(x, y - 1) && !isMoveInCurrentTick)
        {
            setPosition(x, y - 1);
        }
        else if (direction == 2 && map.canMove(x + 1, y) && !isMoveInCurrentTick)
        {
            setPosition(x + 1, y);
        }
        else if (direction == 3 && map.canMove(x, y + 1) && !isMoveInCurrentTick)
        {
            setPosition(x, y + 1);
        }
        else if (direction == 4 && map.canMove(x - 1, y) && !isMoveInCurrentTick)
        {
            setPosition(x - 1, y);
        }

        if (isMoveInCurrentTick)
            break;
    }

    movingCount++;
}

void Entity::changeDirection()
{
    int attemptsToFindDirection = 10;

    for (int i = 0; i < attemptsToFindDirection; i++)
    {
        direction = Utils::getRandomInt(1, 4); // 1 - up, 2 - right, 3 - down, 4 - left
        if (direction == 1 && map.canMove(x, y - 1))
        {
            break;
        }
        else if (direction == 2 && map.canMove(x + 1, y))
        {
            break;
        }
        else if (direction == 3 && map.canMove(x, y + 1))
        {
            break;
        }
        else if (direction == 4 && map.canMove(x - 1, y))
        {
            break;
        }
    }
}

void Entity::takeDamage(int damage)
{
    health -= damage;
    if (health <= 0)
    {
        isAlive = false;
    }
}

void Entity::updateState()
{

}

void Entity::setPosition(int x, int y)
{
    this->x = x;
    this->y = y;

    isMoveInCurrentTick = true;
}

Entity::~Entity() {};
