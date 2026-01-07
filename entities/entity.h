#pragma once
#include <iostream>



class Entity
{
public:
    Entity(int health, int damage, std::string view, int x, int y);
    virtual ~Entity();

    virtual void move();
    void setPosition(int x, int y);


    int getHealth() const { return this->health; };
    int getDamage() const { return this->damage; };
    std::string getView() const { return this->view; };
    int getX() const { return this->x; };
    int getY() const { return this->y; };

private:
    int health;
    int damage;
    std::string view;
    int x;
    int y;
};
