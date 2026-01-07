#include <iostream>
#include "map.h"
#include "entities/monkey.h"



Map::Map(const std::vector<std::shared_ptr<Monkey>>& monkeys)
    : monkeysRef(monkeys)
{
    std::cout << GREEN;
}

void Map::render() const
{
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            std::cout << "" << getObjectView(x, y);
        }
        std::cout << std::endl;
    }
}

std::string Map::getObjectView(int x, int y) const
{
    for (auto monkey : monkeysRef)
    {
        if (monkey->getX() == x && monkey->getY() == y) return monkey->getView();
    }

    return grass;
}

std::string Map::getObjectOnCell(int x, int y)
{
    if (x < 0 || x > WIDTH || y < 0 || y > HEIGHT) return "null";

    for (auto monkey : monkeysRef)
    {
        if (monkey->getX() == x && monkey->getY() == y) return "monkey";
    }

    return "empty";
}

bool Map::canMove(int x, int y) const
{
    return true;
}

Map::~Map()
{
    
}
