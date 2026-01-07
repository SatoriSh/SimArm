#pragma once
#include <iostream>
#include <random>

class Utils
{
public:
    std::string getRandomDirection(int direction) const;
    int getRandomInt(int min, int max) const;
private:
    std::mt19937 rng{ std::random_device{}() };
};
