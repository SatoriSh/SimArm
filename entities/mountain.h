#pragma once
#include <iostream>
#include "naturalObjects.h"

class Mountain : public NaturalObjects
{
public:
    Mountain(int health, int resourceAmount, std::string view, int x, int y);
    ~Mountain();
};
