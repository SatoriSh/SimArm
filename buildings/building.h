#pragma once
#include <string>
#include "../entities/entity.h"

class Building : public Entity
{
  public:
    Building(std::string v, int wN, int rN, int x, int y, Map& map);
    virtual ~Building();

    int getWoodNeedForBuild() const;
    int getRockNeedForBuild() const;
    /*int getX() const;
    int getY() const;
    std::string getView() const;*/

  private:
    int woodNeedForBuild;
    int rockNeedForBuild;
   /* std::string view;
    int x;
    int y;*/
};
