#include "map.h"
#include "utils/utils.h"
#include "entities/entity.h"
#include "entities/monkey.h"
#include "entities/naturalObjects.h"
#include "buildings/building.h"

Map::Map(std::vector<std::shared_ptr<Monkey>> &monkeys, std::vector<std::shared_ptr<NaturalObjects>> &naturalObjects,
         std::vector<std::shared_ptr<Building>> &buildings)
    : monkeysRef(monkeys), naturalObjectsRef(naturalObjects), buildingsRef(buildings)
{

}

void Map::render() const
{
    std::cout << Utils::CYAN << "\t\t  " << std::string(WIDTH * 2, '-') << "\n" << Utils::GREEN;
    for (int y = 0; y < HEIGHT; y++)
    {
        std::cout << "\t\t ";
        for (int x = 0; x < WIDTH; x++)
        {
            if (x == 0)
                std::cout << Utils::CYAN << "|" << Utils::GREEN;
            std::cout << "" << getObjectView(x, y);
            if (x == WIDTH - 1)
                std::cout << Utils::CYAN << "|" << Utils::GREEN;
        }
        std::cout << "\n"; // \n быстрее чем std::endl
    }
    std::cout << Utils::RESET;
}

std::string Map::getObjectView(int x, int y) const
{
    for (const std::shared_ptr<Monkey>& monkey : monkeysRef)
    {
        if (monkey->getX() == x && monkey->getY() == y) return monkey->getView();
    }
    for (const std::shared_ptr<NaturalObjects>& naturalObject : naturalObjectsRef)
    {
        if (naturalObject->getX() == x && naturalObject->getY() == y) return naturalObject->getView();
    }
    for (const std::shared_ptr<Building> &building : buildingsRef)
    {
        if (building->getX() == x && building->getY() == y)
            return building->getView();
    }

    return grass;
}

std::shared_ptr<Entity> Map::getObjectOnCell(int x, int y) const
{
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
        return std::make_shared<Entity>(0, 0, " ", x, y, const_cast<Map &>(*this));

    for (const std::shared_ptr<Monkey>& monkey : monkeysRef)
    {
        if (monkey->getX() == x && monkey->getY() == y) return monkey;
    }
    for (const std::shared_ptr<NaturalObjects>& naturalObject : naturalObjectsRef)
    {
        if (naturalObject->getX() == x && naturalObject->getY() == y) return naturalObject;
    }
    for (const std::shared_ptr<Building> &building : buildingsRef)
    {
        if (building->getX() == x && building->getY() == y) return building;
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
