#include "consoleUI.h"
#include "../utils/utils.h"


ConsoleUI::ConsoleUI(World& w) 
    : world(w)
{

}

void ConsoleUI::showPanelUI() const
{
    drawSeparator();
    std::cout << Utils::RED << "\t\t\t\t\t\t\t\t    ИНФОРМАЦИЯ:" << Utils::BLUE << std::endl;
    std::cout << "\t\t\t\t\t\t\tДерево: " << world.getWoodCount() << "    Камень: " << world.getRockCount() << "    Армяне: " << world.monkeys.size() << std::endl;
    drawSeparator();

    std::cout << Utils::RED << "\t\t\t\t\t\t\t    КЛАВИШИ ДЛЯ ВЗАИМОДЕЙСТВИЯ:" << Utils::BLUE << std::endl;
    std::cout << "\t\t\t\t\t\t\t1 - создать армяна\n\t\t\t\t\t\t\t2 - заспавнить случайный ресурс\n\t\t\t\t\t\t\t3 - начать волну " "пропустив время ожидания" << std::endl;

    std::cout << Utils::RESET;

    if (logs.size() < 1)
        return;

    for (int i = int(logs.size()); i >= int(logs.size()) - logsCountToShow; i--)
    {
        try
        {
            std::cout << logs.at(i) << std::endl;
        }
        catch (const std::out_of_range)
        {
            // pass
        }
    }
}

void ConsoleUI::log(const std::string& message, const std::string& color)
{
    logs.push_back(color + message + Utils::RESET);
}

void ConsoleUI::drawSeparator() const
{
    std::cout << Utils::CYAN;
    std::cout << "\t\t  " << std::string(world.map.getWidth() * 2, '-') << "\n";
    std::cout << Utils::RESET;
}

ConsoleUI::~ConsoleUI()
{

}
