#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include "entities/monkey.h"



class Map
{
public:
    Map(const std::vector<std::shared_ptr<Monkey>>& monkeys);

    ~Map();
    void render() const;

    std::string getObjectOnCell(int x, int y) const;
    bool canMove(int x, int y) const; // по сути карте лучше знать

private:
    const int HEIGHT = 30;
    const int WIDTH = 90;
    std::string grass = "~^";
    const std::vector<std::shared_ptr<Monkey>>& monkeysRef; // ссылка на вектор monkeys
    std::string getObjectView(int x, int y) const;

};
