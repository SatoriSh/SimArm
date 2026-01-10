#include <iostream>
#include "map.h"
#include "entities/monkey.h"
#include "utils/utils.h"


Map::Map(const std::vector<std::shared_ptr<Monkey>>& monkeys)
    : monkeysRef(monkeys)
{
}

void Map::render() const
{
    std::cout << Utils::GREEN;
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            std::cout << "" << getObjectView(x, y);
        }
        std::cout << std::endl;
    }
    std::cout << Utils::RESET;
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
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
        return false;

    return true;
}

Map::~Map()
{

}
