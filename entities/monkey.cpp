#include <iostream>
#include "monkey.h"
#include "../map.h"
#include "naturalObjects.h"

Monkey::Monkey(int health, int damage, std::string view, int x, int y, Map& map)
    : Entity(health, damage, view, x, y, map) // вызвать конструктор родителя
{

}

void Monkey::explore()
{
    auto entityOnCellUp = map.getObjectOnCell(x, y - 1);
    naturalObject = std::dynamic_pointer_cast<NaturalObjects>(entityOnCellUp); // если entityOnCellUp это не NaturalObjects, то naturalObject = nullptr
    if (naturalObject != nullptr) return;
    auto entityOnCellDown = map.getObjectOnCell(x, y + 1);
    naturalObject = std::dynamic_pointer_cast<NaturalObjects>(entityOnCellDown);
    if (naturalObject != nullptr) return;
    auto entityOnCellLeft = map.getObjectOnCell(x - 1, y);
    naturalObject = std::dynamic_pointer_cast<NaturalObjects>(entityOnCellLeft);
    if (naturalObject != nullptr) return;
    auto entityOnCellRight = map.getObjectOnCell(x + 1, y);
    naturalObject = std::dynamic_pointer_cast<NaturalObjects>(entityOnCellRight);
}

void Monkey::mining()
{
    naturalObject.get()->takeDamage(damage);
}

void Monkey::updateState()
{
    explore();
    if (naturalObject == nullptr)
    {
        move();
    }
    else
    {
        mining();
    }
}

Monkey::~Monkey() {};
