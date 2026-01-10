#include "map.h"
#include "utils/utils.h"



Map::Map(const std::vector<std::shared_ptr<Monkey>>& monkeys, const std::vector<std::shared_ptr<Mountain>>& mountains)
    : monkeysRef(monkeys), mountainsRef(mountains)
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
    for (const std::shared_ptr<Monkey>& monkey : monkeysRef)
    {
        if (monkey->getX() == x && monkey->getY() == y) return monkey->getView();
    }
    for (const std::shared_ptr<Mountain>& mountain : mountainsRef)
    {
        if (mountain->getX() == x && mountain->getY() == y) return mountain->getView();
    }

    return grass;
}

std::shared_ptr<void> Map::getObjectOnCell(int x, int y) const
{

    for (const std::shared_ptr<Monkey>& monkey : monkeysRef)
    {
        if (monkey->getX() == x && monkey->getY() == y) return monkey;
    }
    for (const std::shared_ptr<Mountain>& mountain : mountainsRef)
    {
        if (mountain->getX() == x && mountain->getY() == y) return mountain;
    }

    return nullptr;
}

bool Map::canMove(int x, int y) const
{
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
        return false;

    if (getObjectOnCell(x, y) != nullptr)
        return false;


    return true;
}

Map::~Map()
{

}
