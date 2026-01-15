#include "consoleUI.h"
#include "../utils/utils.h"


ConsoleUI::ConsoleUI(World& w) 
    : world(w)
{

}

void ConsoleUI::showPanelUI() const
{
    drawSeparator();
    std::cout << Utils::RED << "\t\t\t\t\t\t\t\t    ИНФОРМАЦИЯ:" << Utils::BLUE << std::endl; // УБРАТЬ TTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT
    std::cout << "\t\t\t\t\t\t\tДоски: " << world.getWoodCount() << "    Камни: " << world.getRockCount() << "    Армяне: " << world.monkeys.size() << std::endl;
    drawSeparator();
    
    std::cout << Utils::RED << "\t\t\t\t\t\t\t    КЛАВИШИ ДЛЯ ВЗАИМОДЕЙСТВИЯ:" << Utils::BLUE << std::endl;
    std::cout << "\t\t\t\t\t\t\t1 - создать армяна\n\t\t\t\t\t\t\t2 - заспавнить случайный ресурс\n\t\t\t\t\t\t\tпробел - пауза/продолжить" << std::endl;
    drawSeparator();
    std::cout << Utils::RED << std::string(70, ' ') << "ЛОГИ:" << Utils::BLUE << "\n";

    if (logs.size() < 1)
        return;

    for (int i = int(logs.size()); i >= int(logs.size()) - logsCountToShow; i--)
    {
        try
        {
            std::cout << "\r";
            std::cout << std::string(56, ' ') << logs.at(i) << "\n";
        }
        catch (const std::out_of_range)
        {
            // pass
        }
    }
}

void ConsoleUI::log(const std::string& message, const std::string& color)
{
    logs.push_back(Utils::RESET + getLocalTime() + ": " + color + message + Utils::RESET);
}

std::string ConsoleUI::getLocalTime() const
{
    std::time_t t = std::time(nullptr);
    std::tm local{};

    localtime_s(&local, &t);

    std::ostringstream oss;
    oss << std::put_time(&local, "%H:%M:%S");
    return oss.str();
}

void ConsoleUI::drawSeparator() const
{
    std::cout << Utils::CYAN;
    std::cout << "\t\t  " << std::string(world.map.getWidth() * 2, '-') << "\n";
}

ConsoleUI::~ConsoleUI()
{

}
