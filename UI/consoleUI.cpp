#include "consoleUI.h"
#include "../utils/utils.h"

void ConsoleUI::log(const std::string message, const std::string color) const
{
    std::cout << color << message << Utils::RESET;
}
