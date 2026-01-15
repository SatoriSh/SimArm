#include <iostream>
#include "naturalObjects.h"


NaturalObjects::NaturalObjects(ResourceType rt, int h, int ra, std::string v, int x, int y, Map& m)
    : Entity(h, 0, v, x, y, m)
{

}

NaturalObjects::~NaturalObjects()
{

}
