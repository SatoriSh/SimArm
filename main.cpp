#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include "map.h"
#include "entities/monkey.h"
#include "utils/utils.h"

int updateTime = 200;
const int bootSplashTime = 10;
const int logoAnimationUpdateTime = 10;

void showBootSplash();
void moveMonkeys();
void sleep(int);

std::vector<std::shared_ptr<Monkey>> monkeys;
Map map(monkeys);

int main()
{
    std::cout << std::endl;
    Utils::hideCursor();

    showBootSplash();

    monkeys.push_back(std::make_shared<Monkey>(100, 15, "🦍", 0, 0));
    monkeys.push_back(std::make_shared<Monkey>(100, 15, "🦍", 89, 5));
    monkeys.push_back(std::make_shared<Monkey>(100, 15, "🦍", 89, 6));
    monkeys.push_back(std::make_shared<Monkey>(100, 15, "🦍", 89, 7));
    monkeys.push_back(std::make_shared<Monkey>(100, 15, "🦍", 5, 29));
    monkeys.push_back(std::make_shared<Monkey>(100, 15, "🦍", 5, 29));
    monkeys.push_back(std::make_shared<Monkey>(100, 15, "🦍", 6, 29));
    monkeys.push_back(std::make_shared<Monkey>(100, 15, "🦍", 7, 29));
    monkeys.push_back(std::make_shared<Monkey>(100, 15, "🦍", 8, 29));
    monkeys.push_back(std::make_shared<Monkey>(100, 15, "🦍", 9, 29));


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
