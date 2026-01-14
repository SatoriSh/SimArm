#include "world.h"
#include "../utils/utils.h"
#include <string>

World::World() 
    : map(monkeys, naturalObjects)
{
    pause = false;
    monkeys.push_back(std::make_shared<Monkey>(100, 15, "🦍", map.getWidth() - 1, 0));
    monkeys.push_back(std::make_shared<Monkey>(100, 15, "🦍", 0, map.getHeight() - 1));
}

int World::getUpdateTime() const
{
    return updateTime;
}

void World::updateTick()
{
    moveMonkeys();
    map.render();
}

void World::moveMonkeys()
{
    for (std::shared_ptr<Monkey>& monkey : monkeys)
    {
        monkey->move(map);
    }
}

void World::addMonkey()
{
    int x;
    int y;

    for (int i = 0; i < attemptsToSpawn; i++)
    {
        x = Utils::getRandomInt(0, map.getWidth() - 1);
        y = Utils::getRandomInt(0, map.getHeight() - 1);
        if (map.getObjectOnCell(x,y) == nullptr)
        {
            monkeys.push_back(std::make_shared<Monkey>(100, 15, "🦍", x, y));
            onEvent("Создан новый армян! Теперь их " + std::to_string(monkeys.size()), Utils::GREEN); // emit
            break;
        }
    }
}

void World::setEventHandler(std::function<void(const std::string &, const std::string &)> handler)
{
    onEvent = handler;
}

int World::getWoodCount() const
{
    return woodCount;
}
int World::getRockCount() const
{
    return rockCount;
}

World::~World()
{

}
