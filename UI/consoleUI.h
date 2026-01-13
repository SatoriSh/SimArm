#pragma once
#include <iostream>
#include <vector>

class ConsoleUI {
  public:
    void log(const std::string& message, const std::string& color);
    void showPanelUI() const;
  private:
      std::vector<std::string> logs;
    int logsCountToShow = 3;
};
