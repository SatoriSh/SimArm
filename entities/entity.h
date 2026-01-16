#pragma once
#include <iostream>
#include <string>
#include "../utils/utils.h"

class Map; // класс map существует, подробности позже

class Entity
{
public:
    Entity(int health, int damage, std::string view, int x, int y, Map& map);
    virtual ~Entity();

    void move();
    void setPosition(int x, int y);

    int getHealth() const { return this->health; };
    int getDamage() const { return this->damage; };
    std::string getView() const { return this->view; };
    int getX() const { return this->x; };
    int getY() const { return this->y; };
    virtual void takeDamage(int damage);
    virtual void updateState();
    void changeDirection();
    bool isAlive = true;
  protected:
    int health;
    int damage;
    std::string view;
    int x;
    int y;
    Map &map;
    bool isMoveInCurrentTick = false;
    int direction;
    int movingCount = 0;
    const int moveCountInOneDirection = Utils::getRandomInt(3, 8);
};
