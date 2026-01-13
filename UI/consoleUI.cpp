#include "consoleUI.h"
#include "../utils/utils.h"

void ConsoleUI::showPanelUI() const
{
    /*
    std::cout << Utils::CYAN << std::endl;

    std::cout << Utils::RED << "\t\tÈÍÔÎÐÌÀÖÈß" << Utils::BLUE << std::endl;
    std::cout << "\t\t      Äåðåâî: " << woodCount << "    Êàìåíü: " << rockCount << "    Àðìÿíå: " << monkeys.size() << std::endl;

    std::cout << Utils::RED << "\t\tÊËÀÂÈØÈ ÄËß ÂÇÀÈÌÎÄÅÉÑÒÂÈß" << Utils::BLUE << std::endl;
    std::cout << "\t\t\t\t1 - ñîçäàòü àðìÿíà\n\t\t\t\t2 - çàñïàâíèòü ñëó÷àéíûé ðåñóðñ\n\t\t\t\t3 - íà÷àòü âîëíó " "ïðîïóñòèâ âðåìÿ îæèäàíèÿ" << std::endl;

    std::cout << Utils::RESET;
    */

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
