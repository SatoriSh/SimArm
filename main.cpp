#ifdef _WIN32
#include <windows.h>
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


const int bootSplashTime = 1000;
const int logoAnimationUpdateTime = 50;

void showBootSplash();
void sleep(int);

World world;

int main()
{
    #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    #endif

    std::cout << std::endl;
    Utils::hideCursor();

    showBootSplash();

    while (true)
    {
        Utils::moveCursorHome();

        world.updateTick();

        sleep(world.getUpdateTime());
    }

    return 0;
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
