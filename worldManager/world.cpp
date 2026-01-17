#include <string>
#include <algorithm>
#include "world.h"
#include "../utils/utils.h"

World::World() 
    : map(monkeys, naturalObjects, buildings)
{
    pause = false;
}

int World::getUpdateTime() const
{
    return updateTime;
}

void World::updateTick()
{
    points++;

    updateEntitiesState();

    refreshEntities();

    map.render();
}

void World::refreshEntities()
{
    // это по хорошему надо проверять в updateState у naturalObject, но мне уже лень
    for (const std::shared_ptr<NaturalObjects> &naturalObject : naturalObjects)
    {
        if (!naturalObject.get()->isAlive) 
        {
            if (naturalObject.get()->getResourceType() == NaturalObjects::Wood)
            {
                woodCount += naturalObject.get()->getResourceAmount();
                onEvent("Добыто " + std::to_string(naturalObject.get()->getResourceAmount()) + " древесины                                                     ",
                        Utils::GRAY);
            }
            else if (naturalObject.get()->getResourceType() == NaturalObjects::Rock)
            {
                rockCount += naturalObject.get()->getResourceAmount();
                onEvent("Добыто " + std::to_string(naturalObject.get()->getResourceAmount()) + " камня                                                     ", 
                        Utils::GRAY);
            }
        }
    }

    monkeys.erase(std::remove_if(monkeys.begin(), monkeys.end(),
                                 [](const std::shared_ptr<Monkey> &m)
                                 {
                                     return !m->isAlive; 
                                 }),
                  monkeys.end());

    naturalObjects.erase(std::remove_if(naturalObjects.begin(), naturalObjects.end(),
                                        [](const std::shared_ptr<NaturalObjects> &n) { return !n->isAlive; }),
                  naturalObjects.end());
}

void World::updateEntitiesState()
{
    for (std::shared_ptr<Monkey>& monkey : monkeys)
    {
        monkey->updateState();
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
                if (points >= getPointsNeedToSpawnNaturalObject())
                {
                    probability = Utils::getRandomInt(0, 10); // кому не похуй на магические числа
                    if (probability >= 3)
                    {
                        naturalObjects.push_back(
                            std::make_shared<Tree>(120, Utils::getRandomInt(6, 12), "🌳", x, y, map));
                        onEvent("Создано новое дерево                                                      ", Utils::GREEN);
                    }
                    else
                    {
                        naturalObjects.push_back(
                            std::make_shared<Mountain>(250, Utils::getRandomInt(15, 25), "⛰️", x, y, map));
                        onEvent("Создана новая гора                                                      ", Utils::GREEN);
                    }
                    points -= getPointsNeedToSpawnNaturalObject();
                }
                else
                {
                    onEvent("Недостаточно очков                                                      ", Utils::RED);
                }
                break;
            case monkey:
                if (points >= getPointsNeedToSpawnMonkey())
                {
                    monkeys.push_back(std::make_shared<Monkey>(100, 15, "🦍", x, y, map));
                    onEvent("Создан новый армян                                                      ", Utils::CYAN); 
                    points -= getPointsNeedToSpawnMonkey();
                }
                else
                {
                    onEvent("Недостаточно очков                                                      ", Utils::RED);
                }
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

void World::setUpdateTime(char operation)
{
    if (operation == '+')
        updateTime += updateTimeChangeValue;
    else if (operation == '-')
        updateTime -= updateTimeChangeValue;

    if (updateTime < minUpdateTime)
        updateTime = minUpdateTime;
    else if (updateTime > maxUpdateTime)
        updateTime = maxUpdateTime;

    onEvent("Время обновления мира изменено: " + std::to_string(updateTime) + "мс                                                   ", Utils::YELLOW);
}

int World::getWoodCount() const
{
    return woodCount;
}
int World::getRockCount() const
{
    return rockCount;
}
int World::getPoints() const
{
    return points;
}
int World::getPointsNeedToSpawnNaturalObject() const
{
    return pointsNeedToSpawnNaturalObject;
}
int World::getPointsNeedToSpawnMonkey() const
{
    return pointsNeedToSpawnMonkey;
}

World::~World()
{

}
