#include <iostream>
#include "utils.h"
#include <random>

int Utils::getRandomInt(int min, int max) const
{
    static std::mt19937 rng{ std::random_device{}() };
    std::uniform_int_distribution<int> dist(min, max);
    return dist(rng);
}
