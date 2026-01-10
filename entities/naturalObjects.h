#pragma once
#include <iostream>

class NaturalObjects
{
public:
    enum ResourceType
    {
        wood,
        rock
    };

    NaturalObjects(ResourceType resourceType, int health, int resourceAmount, std::string view, int x, int y);
    virtual ~NaturalObjects();

    int getHealth() const { return health; };
    int getResourceAmount() const { return resourceAmount; };
    int getX() const { return x; };
    int getY() const { return y; };
    std::string getView() const { return view; };
    ResourceType getResourceType() const { return resourceType; };

private:
    ResourceType resourceType;
    int health;
    int resourceAmount;
    std::string view;
    int x;
    int y;
};
