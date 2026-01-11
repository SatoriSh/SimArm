#include "world.h"
#include "../utils/utils.h"

World::World() 
    : map(monkeys, naturalObjects)
{
    monkeys.push_back(std::make_shared<Monkey>(100, 15, "🦍", 5,2));
    monkeys.push_back(std::make_shared<Monkey>(100, 15, "🦍", 41, 4));
    monkeys.push_back(std::make_shared<Monkey>(100, 15, "🦍", 13, 5));
    monkeys.push_back(std::make_shared<Monkey>(100, 15, "🦍", 34, 7));
    monkeys.push_back(std::make_shared<Monkey>(100, 15, "🦍", 15, 13));
    monkeys.push_back(std::make_shared<Monkey>(100, 15, "🦍", 49, 9));
    monkeys.push_back(std::make_shared<Monkey>(100, 15, "🦍", 23, 17));
}

int World::getUpdateTime() const
{
    return updateTime;
}

void World::updateTick()
{
    showInfo();

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

void World::showInfo()
{
    std::cout << Utils::CYAN;
    std::cout << "Wood: " << woodCount << std::endl;
    std::cout << "Rock: " << rockCount << std::endl;
    std::cout << "Monkeys: " << monkeys.size() << "\n\n";
    std::cout << Utils::RESET;
}

World::~World()
{

}
