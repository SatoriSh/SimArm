#include <iostream>
#include "naturalObjects.h"


naturalObjects::naturalObjects(ResourceType rt,int h, int ra, std::string v)
    : resourceType(rt), health(h), resourceAmount(ra), view(v)
{
    
}



naturalObjects::~naturalObjects() {};
