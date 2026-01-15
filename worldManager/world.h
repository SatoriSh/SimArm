#pragma once
#include <vector>
#include <memory>
#include <functional>
#include "../map.h"
#include "../entities/monkey.h"
#include "../entities/naturalObjects.h"
#include "../entities/tree.h"
#include "../entities/mountain.h"

class World
{
  public:
    World();
    ~World();
    
    enum ObjectTypeToSpawnType
    {
        naturalObject,
        monkey
    };
    ObjectTypeToSpawnType objectTypeToSpawn = ObjectTypeToSpawnType::naturalObject;

    int getUpdateTime() const;
    void updateTick();
    void addObject(ObjectTypeToSpawnType objectTypeToSpawn);
    void setEventHandler(std::function<void(const std::string &, const std::string &)> handler); // обработчик для сигнала
    int getWoodCount() const;
    int getRockCount() const;

    std::vector<std::shared_ptr<Monkey>> monkeys;
    std::vector<std::shared_ptr<NaturalObjects>> naturalObjects;
    Map map;

    bool pause;

  private:
    int updateTime = 250;
    int woodCount = 0;
    int rockCount = 0;
    int attemptsToSpawn = 100;
    void moveMonkeys();

    std::function<void(const std::string &, const std::string &)> onEvent; // сигнал
};
