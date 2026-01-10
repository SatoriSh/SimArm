#pragma once

#include <vector>
#include <memory>
#include "entities/monkey.h"
#include "entities/mountain.h"


class Map
{
public:
    Map(const std::vector<std::shared_ptr<Monkey>>& monkeys, const std::vector<std::shared_ptr<Mountain>>& mountains);
    ~Map();
    
    void render() const;
    bool canMove(int x, int y) const; // по сути карте лучше знать

private:
    const int HEIGHT = 30;
    const int WIDTH = 90;
    std::string grass = "~^";
    const std::vector<std::shared_ptr<Monkey>>& monkeysRef; // ссылка на вектор monkeys
    const std::vector<std::shared_ptr <Mountain>>& mountainsRef;
    std::string getObjectView(int x, int y) const;
    std::shared_ptr<void> getObjectOnCell(int x, int y) const;
};
