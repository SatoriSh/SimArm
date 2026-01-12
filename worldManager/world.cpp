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
