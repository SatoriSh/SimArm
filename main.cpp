#ifdef _WIN32
#include <windows.h>
#include <conio.h> // для проверки нажатия клавиш
#endif

#include <vector>
#include <thread>
#include <chrono>
#include "utils/utils.h"
#include "map.h"
#include "entities/entity.h"
#include "entities/naturalObjects.h"
#include "entities/mountain.h"
#include "entities/tree.h"
#include "worldManager/world.h"


const int bootSplashTime = 250;
const int logoAnimationUpdateTime = 25;

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

    std::cout << std::endl;
    Utils::hideCursor();

    showBootSplash();

    while (true)
    {
        Utils::moveCursorHome();
        
        inputHandler();
        world.updateTick();

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
            world.addMonkey();
        else if (ch == ' ') // space
            world.pause = !world.pause;

        while (_kbhit()) char a = _getch(); // очистка буффера чтобы игрок не смог заспамить команды
    }
}

void showBootSplash()
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
