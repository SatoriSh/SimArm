#include "building.h"

Building::Building(std::string v, int wN, int rN, int x, int y, Map& m)
    : Entity(0, 0, v, x, y, m),
    woodNeedForBuild(wN), rockNeedForBuild(rN)
{

}

int Building::getWoodNeedForBuild() const
{
    return woodNeedForBuild;
}
int Building::getRockNeedForBuild() const
{
    return rockNeedForBuild;
}

Building::~Building()
{
}
