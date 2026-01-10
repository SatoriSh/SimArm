#include <vector>
#include <thread>
#include <chrono>
#include "utils/utils.h"
#include "map.h"
#include "entities/monkey.h"
#include "entities/naturalObjects.h"

int updateTime = 5000;
const int bootSplashTime = 10;
const int logoAnimationUpdateTime = 10;

void showBootSplash();
void moveMonkeys();
void sleep(int);

std::vector<std::shared_ptr<Monkey>> monkeys;
std::vector<std::shared_ptr<Mountain>> mountains;



Map map(monkeys, mountains);

int main()
{
    std::cout << std::endl;
    Utils::hideCursor();

    showBootSplash();

    monkeys.push_back(std::make_shared<Monkey>(100, 15, "🦍", 2, 1));
    monkeys.push_back(std::make_shared<Monkey>(100, 15, "🦍", 3, 2));
    monkeys.push_back(std::make_shared<Monkey>(100, 15, "🦍", 89, 6));
    monkeys.push_back(std::make_shared<Monkey>(100, 15, "🦍", 89, 7));
    monkeys.push_back(std::make_shared<Monkey>(100, 15, "🦍", 5, 29));
    monkeys.push_back(std::make_shared<Monkey>(100, 15, "🦍", 5, 29));
    monkeys.push_back(std::make_shared<Monkey>(100, 15, "🦍", 6, 29));
    monkeys.push_back(std::make_shared<Monkey>(100, 15, "🦍", 7, 29));
    monkeys.push_back(std::make_shared<Monkey>(100, 15, "🦍", 8, 29));
    monkeys.push_back(std::make_shared<Monkey>(100, 15, "🦍", 9, 29));


    mountains.push_back(std::make_shared<Mountain>(40, 15, "⛰️ ", 1, 1));
    mountains.push_back(std::make_shared<Mountain>(40, 15, "⛰️ ", 2, 2));
    mountains.push_back(std::make_shared<Mountain>(40, 15, "⛰️ ", 3, 3));
    mountains.push_back(std::make_shared<Mountain>(40, 15, "⛰️ ", 4, 4));


    while (true)
    {
        Utils::moveCursorHome();
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
}

void sleep(int time) { std::this_thread::sleep_for(std::chrono::milliseconds(time)); };
