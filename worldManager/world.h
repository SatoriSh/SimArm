#pragma once
#include <vector>
#include <memory>
#include <functional>
#include "../map.h"
#include "../entities/monkey.h"
#include "../entities/naturalObjects.h"
#include "../entities/tree.h"
#include "../entities/mountain.h"
#include "../buildings/building.h"
#include "../buildings/church.h"

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
    int getPoints() const;
    int getPointsNeedToSpawnNaturalObject() const;
    int getPointsNeedToSpawnMonkey() const;
    int getChurchCount() const;
    void setUpdateTime(char operation);
    std::vector<std::shared_ptr<Monkey>> monkeys;
    std::vector<std::shared_ptr<NaturalObjects>> naturalObjects;
    std::vector<std::shared_ptr<Building>> buildings;
    Map map;

    bool pause;

  private:
    int updateTime = 550;
    const int minUpdateTime = 50;
    const int maxUpdateTime = 1050;
    const int updateTimeChangeValue = 100;
    int woodCount = 0;
    int rockCount = 0;
    int attemptsToSpawn = 100;
    int points = 0;
    int pointsNeedToSpawnNaturalObject = 10;
    int pointsNeedToSpawnMonkey = 30;
    int woodToBuildChurch = 33;
    int rockToBuildChurch = 20;
    int churchCount;
    void updateEntitiesState();
    void refreshEntities();
    std::function<void(const std::string &, const std::string &)> onEvent; // сигнал
};
