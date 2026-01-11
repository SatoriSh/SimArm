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

int updateTime = 100;
const int bootSplashTime = 1000;
const int logoAnimationUpdateTime = 10;

void showBootSplash();
void showInfo();
void moveMonkeys();
void sleep(int);

std::vector<std::shared_ptr<Monkey>> monkeys;
std::vector<std::shared_ptr<NaturalObjects>> naturalObjects;

Map map(monkeys, naturalObjects);

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
        showInfo();
        map.render();

        moveMonkeys();
        sleep(updateTime);
    }

    return 0;
}

void moveMonkeys()
{
    for (auto monkey : monkeys)
    {
        monkey->move(map);
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

void showInfo()
{
    std::cout << Utils::CYAN;
    std::cout << "Wood: 1213\n";
    std::cout << "Rock: 531\n";
    std::cout << "Monkey: 37\n\n";
    std::cout << Utils::RESET;
}

void sleep(int time) { std::this_thread::sleep_for(std::chrono::milliseconds(time)); };
