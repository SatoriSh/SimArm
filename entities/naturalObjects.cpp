#include <iostream>
#include "naturalObjects.h"


NaturalObjects::NaturalObjects(ResourceType rt, int h, int ra, std::string v, int x, int y, Map& m)
    : Entity(h, 0, v, x, y, m), 
    resourceAmount(ra), resourceType(rt)
{

}

int NaturalObjects::getMinResAmount() const
{
    if (resourceType == ResourceType::Wood)
        return 24;
    else if (resourceType == ResourceType::Rock)
        return 32;
}
int NaturalObjects::getMaxResAmount() const
{
    if (resourceType == ResourceType::Wood)
        return 35;
    else if (resourceType == ResourceType::Rock)
        return 51;
}

NaturalObjects::~NaturalObjects()
{

}
