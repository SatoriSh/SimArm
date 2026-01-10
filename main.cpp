#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include "map.h"
#include "entities/monkey.h"
#include "utils/utils.h"

const void moveCursorHome() { std::cout << "\033[H"; }
const void hideCursor() { std::cout << "\033[?25l"; }

int updateTime = 1000;
const int bootSplashTime = 2000;
const int logoAnimationUpdateTime = 100;

void showBootSplash();
void moveMonkeys();
void sleep(int);

std::vector<std::shared_ptr<Monkey>> monkeys;
Map map(monkeys);

int main()
{
    std::cout << std::endl;
    hideCursor();

    showBootSplash();

    monkeys.push_back(std::make_shared<Monkey>(100, 15, "🦍", 50, 2));
    monkeys.push_back(std::make_shared<Monkey>(100, 15, "🦍", 51, 2));
    monkeys.push_back(std::make_shared<Monkey>(100, 15, "🦍", 52, 2));
    monkeys.push_back(std::make_shared<Monkey>(100, 15, "🦍", 53, 2));

    while (true)
    {
        moveCursorHome();
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
        monkey->move(map); // как здесь передать map
    }
}

void showBootSplash()
{
    std::cout << Utils::GREEN << "\n\n\n";

    std::cout << "\t\t" << R"( ____  _              _)" << std::endl;
    sleep(logoAnimationUpdateTime);
    std::cout << "\t\t" << R"(/ ___|(_)_ __ ___    / \   _ __ _ __ ___)" << std::endl;
    sleep(logoAnimationUpdateTime);
    std::cout << "\t\t" << R"(\___ \| | '_ ` _ \  / _ \ | '__| '_ ` _ \)" << std::endl;
    sleep(logoAnimationUpdateTime);
    std::cout << "\t\t" << R"( ___) | | | | | | |/ ___ \| |  | | | | | |)" << std::endl;
    sleep(logoAnimationUpdateTime);
    std::cout << "\t\t" << R"(|____/|_|_| |_| |_/_/   \_|_|  |_| |_| |_|)" << std::endl;

    std::cout << std::endl << std::endl << std::endl;

    sleep(bootSplashTime);
}

void sleep(int time) { std::this_thread::sleep_for(std::chrono::milliseconds(time)); };
