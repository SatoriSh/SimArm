#include <iostream>
#include "utils.h"
#include <random>


const std::string Utils::RED = "\033[31m";
const std::string Utils::GREEN = "\033[32m";
const std::string Utils::YELLOW = "\033[33m";
const std::string Utils::BLUE = "\033[34m";
const std::string Utils::MAGENTA = "\033[35m";
const std::string Utils::CYAN = "\033[36m";
const std::string Utils::RESET = "\033[0m";

int Utils::getRandomInt(int min, int max)
{
    static std::mt19937 rng{ std::random_device{}() };
    static std::uniform_int_distribution<int> dist(min, max);
    return dist(rng);
}



void Utils::moveCursorHome() { std::cout << "\033[H"; };
void Utils::hideCursor() { std::cout << "\033[?25l"; };
