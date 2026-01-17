#include "building.h"

Building::Building(std::string v, int wN, int rN, int x, int y, Map& m)
    : Entity(0, 0, view, x, y, map),
    view(v), woodNeedForBuild(wN), rockNeedForBuild(rN), x(x), y(y)
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

//int Building::getX() const
//{
//    return x;
//}
//int Building::getY() const
//{
//    return y;
//}
//std::string Building::getView() const
//{
//    return view;
//}

Building::~Building()
{
}
