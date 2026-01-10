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

// я не ебу что лучше, кинуть всё в один вектор или вот так и похуй
std::vector<std::shared_ptr<Monkey>> monkeys;
std::vector<std::shared_ptr<NaturalObjects>> naturalObjects;

Map map(monkeys, naturalObjects);

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


    naturalObjects.push_back(std::make_shared<Mountain>(40, 15, "⛰️ ", 1, 1));
    naturalObjects.push_back(std::make_shared<Mountain>(40, 15, "⛰️ ", 2, 2));
    naturalObjects.push_back(std::make_shared<Mountain>(40, 15, "⛰️ ", 3, 3));
    naturalObjects.push_back(std::make_shared<Mountain>(40, 15, "⛰️ ", 4, 4));
    naturalObjects.push_back(std::make_shared<Tree>(40, 15, "🌳", 5, 5));
    naturalObjects.push_back(std::make_shared<Tree>(40, 15, "🌳", 6, 6));
    naturalObjects.push_back(std::make_shared<Tree>(40, 15, "🌳", 7, 7));
    naturalObjects.push_back(std::make_shared<Tree>(40, 15, "🌳", 8, 8));


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
