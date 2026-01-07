#include <iostream>
#include "utils.h"
#include <random>

int randomInt(int min, int max)
{

}

int Utils::getRandomInt(int min, int max) const
{
    std::uniform_int_distribution<int> dist(min, max);
    return dist(rng);
}

std::string Utils::getRandomDirection(int direction) const
{
    switch (direction)
    {
    case 1: return "up";
    case 2: return "right";
    case 3: return "down";
    case 4: return "left";
    };
}
