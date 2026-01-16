#pragma once
#include <iostream>
#include <functional>
#include <string>
#include "entity.h"

class NaturalObjects : public Entity
{
public:
    enum ResourceType
    {
        Wood,
        Rock
    };

    NaturalObjects(ResourceType resourceType, int health, int resourceAmount, std::string view, int x, int y, Map& map);
    virtual ~NaturalObjects();
    int getResourceAmount() const { return resourceAmount; };
    ResourceType getResourceType() const { return resourceType; };

    int getMinResAmount() const;
    int getMaxResAmount() const;
  private:
    int resourceAmount;
    int minResAmount;
    int maxResAmount;
    ResourceType resourceType;
};
