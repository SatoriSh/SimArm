#pragma once

#include <vector>
#include <memory>
#include "entities/monkey.h"
#include "entities/naturalObjects.h"


class Map
{
public:
    Map(const std::vector<std::shared_ptr<Monkey>>& monkeys, const std::vector<std::shared_ptr<NaturalObjects>>& naturalObjectsRef);
    ~Map();

    void render() const;
    bool canMove(int x, int y) const; // по сути карте лучше знать

    int getHeight() const { return HEIGHT; };
    int getWidth() const { return WIDTH; };

private:
    const int HEIGHT = 20;
    const int WIDTH = 50;
    std::string grass = "~^";
    const std::vector<std::shared_ptr<Monkey>>& monkeysRef; // ссылка на вектор monkeys
    const std::vector<std::shared_ptr <NaturalObjects>>& naturalObjectsRef;
    std::string getObjectView(int x, int y) const;
    std::shared_ptr<void> getObjectOnCell(int x, int y) const;
};
