#include "consoleUI.h"
#include "../utils/utils.h"


ConsoleUI::ConsoleUI(World& w) 
    : world(w)
{
}

void ConsoleUI::showPanelUI() const
{
    drawSeparator();
    std::cout << Utils::YELLOW << std::string(68, ' ') << "ИНФОРМАЦИЯ:" << Utils::BLUE << std::endl;
    std::cout << std::string(44, ' ') << "Очки: " << world.getPoints() << "    Древесина: " << world.getWoodCount() << "    Камень: " << world.getRockCount()
              << "    Армяне: " << world.monkeys.size() << "    Церкви: " << world.getChurchCount() << "                         \n";
    drawSeparator();

    std::cout << Utils::YELLOW << std::string(60, ' ') << "КЛАВИШИ ДЛЯ ВЗАИМОДЕЙСТВИЯ:" << Utils::BLUE << std::endl;
    std::cout << std::string(56, ' ') << "1 - Создать армяна (нужно " << world.getPointsNeedToSpawnMonkey() << " очков)\n"
              << std::string(56, ' ') << "2 - Создать случайный ресурс (нужно " << world.getPointsNeedToSpawnNaturalObject() << " очков)\n"
              << std::string(56, ' ') << "3 - Ускорить время\n"
              << std::string(56, ' ') << "4 - Замедлить время\n"
              << std::string(56, ' ') << "Space - Пауза/Продолжить\n"
              << std::string(56, ' ') << "Esc - выйти\n";
    drawSeparator();

    std::cout << Utils::YELLOW << std::string(70, ' ') << "ЛОГИ:" << Utils::BLUE << "\n";

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
    std::cout << "\r";
    drawSeparator();
    // цель
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
