#pragma once
#include <vector>
#include <memory>
#include "../map.h"
#include "../entities/monkey.h"
#include "../entities/naturalObjects.h"


class World
{
  public:
    World();
    ~World();
    
    int getUpdateTime() const;
    void updateTick();

    std::vector<std::shared_ptr<Monkey>> monkeys;
    std::vector<std::shared_ptr<NaturalObjects>> naturalObjects;
    Map map; 

  private:
    int updateTime = 1000;
    int woodCount = 0;
    int rockCount = 0;
    void moveMonkeys();
    void showInfo();
};
