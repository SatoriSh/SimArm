#pragma once
#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>
#include <sstream>
#include "../worldManager/world.h"

class ConsoleUI {
  public:
      ConsoleUI(World& world);
      ~ConsoleUI();

      void log(const std::string& message, const std::string& color);
      void showPanelUI() const;
      void drawSeparator() const;
  private:
      std::string getLocalTime() const;
      std::vector<std::string> logs;
      int logsCountToShow = 3;
      World &world;
};
