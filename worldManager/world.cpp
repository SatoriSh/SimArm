#include "world.h"
#include "../utils/utils.h"

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
    if (pause) return;

    moveMonkeys();

    map.render();

    showInfo();
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
            break;
        }
    }
}

void World::showInfo()
{
    std::cout << Utils::CYAN;
    std::cout << std::string(map.getWidth() * 2, '-') << std::endl;
    std::cout << std::string(map.getWidth(), ' ') << Utils::RED << "INFO" << Utils::BLUE << std::endl;
    std::cout << std::string(map.getWidth() / 2, ' ') << "\t\t        Wood: " << woodCount << "    Rock: " << rockCount << "    Monkeys: " << monkeys.size() << std::endl;
    std::cout << Utils::RESET;
}

World::~World()
{

}
