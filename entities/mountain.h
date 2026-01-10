#pragma once
#include "naturalObjects.h"

class mountain : public naturalObjects
{
public:
    mountain(int health, int resourceAmount, std::string view);
    ~mountain();
};
