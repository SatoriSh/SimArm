#include <iostream>
#include "monkey.h"

Monkey::Monkey(int health, int damage, std::string view, int x, int y, Map& map)
    : Entity(health, damage, view, x, y, map) // вызвать конструктор родителя
{
}

void Monkey::explore()
{

}

Monkey::~Monkey() {};
