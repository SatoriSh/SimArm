#ifdef _WIN32
#include <windows.h>
#include <conio.h> // для проверки нажатия клавиш
#endif

#include <vector>
#include <thread>
#include <chrono>
#include <cstdlib>

#include "utils/utils.h"
#include "map.h"
#include "entities/entity.h"
#include "entities/naturalObjects.h"
#include "entities/mountain.h"
#include "entities/tree.h"
#include "worldManager/world.h"
#include "UI/consoleUI.h"

const int bootSplashTime = 500;
const int logoAnimationUpdateTime = 25;

// constexpr - чуть надежнее, переменная вычислится на этапе компиляции
constexpr char SPACE = 32;
constexpr char ESC = 27;

void showBootSplash();
void sleep(int);
void inputHandler();

World world;

int main()
{
    #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD mode;
    GetConsoleMode(hConsole, &mode);
    SetConsoleMode(hConsole, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
    std::cout << "\033[8;65;238t" << std::flush; // команда которая растягивает терминал на 1920x1080
    #endif

    ConsoleUI consoleUI(world);

    world.setEventHandler([&consoleUI](const std::string &message, const std::string &color) { consoleUI.log(message,color); });

    std::cout << std::endl;
    Utils::hideCursor();

    showBootSplash();

    while (true)
    {
        Utils::moveCursorHome();
        
        inputHandler();
        if (!world.pause)
        {
            world.updateTick();
            consoleUI.showPanelUI();
        }

        sleep(world.getUpdateTime());
    }

    return 0;
}

void inputHandler()
{
    if (_kbhit())
    {
        char ch = _getch();

        if (ch == '1' && !world.pause)
            world.addObject(World::ObjectTypeToSpawnType::monkey);
        else if (ch == '2' && !world.pause)
            world.addObject(World::ObjectTypeToSpawnType::naturalObject);
        else if (ch == SPACE)
            world.pause = !world.pause;
        else if (ch == ESC)
        {
            Utils::clearConsole();
            std::exit(0);
        }

        while (_kbhit()) char a = _getch(); // очистка буффера чтобы игрок не смог заспамить команды
    }
}

void showBootSplash() // убрать в systemUI
{
    std::cout << Utils::GREEN;

    std::cout << R"( ____  _              _)" << std::endl;
    sleep(logoAnimationUpdateTime);
    std::cout << R"(/ ___|(_)_ __ ___    / \   _ __ _ __ ___)" << std::endl;
    sleep(logoAnimationUpdateTime);
    std::cout << R"(\___ \| | '_ ` _ \  / _ \ | '__| '_ ` _ \)" << std::endl;
    sleep(logoAnimationUpdateTime);
    std::cout << R"( ___) | | | | | | |/ ___ \| |  | | | | | |)" << std::endl;
    sleep(logoAnimationUpdateTime);
    std::cout << R"(|____/|_|_| |_| |_/_/   \_|_|  |_| |_| |_|)" << std::endl;
    std::cout << std::endl << std::endl << std::endl;
    sleep(bootSplashTime);
    Utils::clearConsole();
}

void sleep(int time) { std::this_thread::sleep_for(std::chrono::milliseconds(time)); };
