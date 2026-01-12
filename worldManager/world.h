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
    void addMonkey();

    std::vector<std::shared_ptr<Monkey>> monkeys;
    std::vector<std::shared_ptr<NaturalObjects>> naturalObjects;
    Map map;

    bool pause;

  private:
    int updateTime = 1000;
    int woodCount = 0;
    int rockCount = 0;
    int attemptsToSpawn = 100;
    void moveMonkeys();
    void showInfo();

};
