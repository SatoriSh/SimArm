#include <iostream>
#include "naturalObjects.h"


NaturalObjects::NaturalObjects(ResourceType rt, int h, int ra, std::string v, int x, int y)
    : resourceType(rt), health(h), resourceAmount(ra), view(v), x(x), y(y)
{
    
}



NaturalObjects::~NaturalObjects() {};
