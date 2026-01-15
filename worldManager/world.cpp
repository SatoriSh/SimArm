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

void World::addObject(ObjectTypeToSpawnType objectTypeToSpawn)
{
    int x;
    int y;
    int probability;
    bool spawned = false;

    for (int i = 0; i < attemptsToSpawn; i++)
    {
        x = Utils::getRandomInt(0, map.getWidth() - 1);
        y = Utils::getRandomInt(0, map.getHeight() - 1);
        if (map.getObjectOnCell(x, y) == nullptr)
        {
            switch (objectTypeToSpawn)
            {
            case naturalObject:
                probability = Utils::getRandomInt(0, 10); // кому не похуй на магические числа
                if (probability >= 4)
                {
                    naturalObjects.push_back(std::make_shared<Tree>(30, 6, "🌳", x, y));
                    onEvent("Создано новое дерево                           ", Utils::GREEN);
                }
                else
                {
                    naturalObjects.push_back(std::make_shared<Mountain>(70, 25, "⛰️", x, y));
                    onEvent("Создана новая гора                           ", Utils::GREEN);
                }
                break;
            case monkey:
                monkeys.push_back(std::make_shared<Monkey>(100, 15, "🦍", x, y));
                onEvent("Создан новый армян                           ", Utils::GREEN); 
                break;
            }
            spawned = true;
        }
        if (spawned)
            return;
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
