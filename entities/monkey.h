#pragma once
#include <vector>
#include "entity.h"

class Map;
class NaturalObjects;

class Monkey : public Entity
{
  public:
    Monkey(int health, int damage, std::string view, int x, int y, Map& map);
    ~Monkey();

    void explore();

  private:
    std::shared_ptr<NaturalObjects> naturalObject;
};
