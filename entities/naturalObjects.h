#pragma once
#include <iostream>

class naturalObjects
{
public:
    enum ResourceType
    {
        wood,
        rock
    };

    naturalObjects(ResourceType resourceType, int health, int resourceAmount, std::string view);
    virtual ~naturalObjects();

    int getHealth() const { return health; };
    int getResourceAmount() const { return resourceAmount; };
    std::string getView() const { return view; };
    ResourceType getResourceType() const { return resourceType; };

private:
    int health;
    int resourceAmount;
    ResourceType resourceType;
    std::string view;
    int x;
    int y;
};
