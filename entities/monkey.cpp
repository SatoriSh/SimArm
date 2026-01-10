#include <iostream>
#include "monkey.h"



Monkey::Monkey(int health, int damage, std::string view, int x, int y)
    : Entity(health, damage, view, x, y) // вызвать конструктор родителя
{
}

Monkey::~Monkey() {};
