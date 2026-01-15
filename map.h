#pragma once
#include <vector>
#include <memory>
#include <string>

class Monkey;
class NaturalObjects;
class Entity;

class Map
{
public:
    Map(const std::vector<std::shared_ptr<Monkey>>& monkeys, const std::vector<std::shared_ptr<NaturalObjects>>& naturalObjectsRef);
    ~Map();

    void render() const;
    bool canMove(int x, int y) const; // по сути карте лучше знать

    int getHeight() const { return HEIGHT; };
    int getWidth() const { return WIDTH; };

    std::shared_ptr<Entity> getObjectOnCell(int x, int y) const;

private:
    const int HEIGHT = 22;
    const int WIDTH = 60;
    std::string grass = "~^";
    const std::vector<std::shared_ptr<Monkey>>& monkeysRef; // ссылка на вектор monkeys
    const std::vector<std::shared_ptr <NaturalObjects>>& naturalObjectsRef;
    std::string getObjectView(int x, int y) const;
};
