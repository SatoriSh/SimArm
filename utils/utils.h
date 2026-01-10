#pragma once
#include <iostream>
#include <random>

class Utils
{
public:
    static int getRandomInt(int min, int max);
    static void moveCursorHome();
    static void hideCursor();
    static void clearConsole();

    // colors
    static const std::string RED;
    static const std::string GREEN;
    static const std::string YELLOW;
    static const std::string BLUE;
    static const std::string MAGENTA;
    static const std::string CYAN;
    static const std::string RESET;
};
