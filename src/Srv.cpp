#include "../include/Srv.hpp"

Srv::Srv(int k, std::vector<int>& checkedPositions) : k_(k), checkedPositions_(checkedPositions) {}

Srv::~Srv() {}

std::pair<int, int> Srv::selectOptimusTime(int* selectRow) {
  std::vector<std::pair<int, int>> optimusTimes;
  for (int i = 0; i < k_; i++) {
    int randomPosition = rand() % 10;
    while (std::find(checkedPositions_.begin(), checkedPositions_.end(), randomPosition) != checkedPositions_.end()) {
      randomPosition = rand() % 10;
    }
    checkedPositions_.push_back(randomPosition);
    optimusTimes.push_back(std::make_pair(randomPosition, selectRow[randomPosition]));
  }
  std::sort(optimusTimes.begin(), optimusTimes.end(), [](std::pair<int, int> a, std::pair<int, int> b) {
    return a.second < b.second;
  });
  return optimusTimes[0];
}
