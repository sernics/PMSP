#include "../include/Srv.hpp"

#include <vector>
#include <iostream>
#include <algorithm>
#include <random>

Srv::Srv(int k, std::vector<int>& checkedPositions, PmspProblem pmsp_problem) : k_(k), checkedPositions_(checkedPositions),
    pmsp_problem_(pmsp_problem) {}

Srv::~Srv() {}

std::pair<int, int> Srv::selectOptimusTime(int* selectRow) {
  std::vector<int> checkedPositions = this->checkedPositions_;
  std::vector<std::pair<int, int>> candidates;
  for (int j = 0; j < this->k_; j++) {
    std::pair<int, int> minimal_time = std::make_pair(9999999, 0);
    for (int i = 0; i < this->pmsp_problem_.getJobs(); i++) {
      if (selectRow[i] < minimal_time.first) {
        if (std::find(checkedPositions.begin(), checkedPositions.end(), i) == checkedPositions.end()) {
          minimal_time.first = selectRow[i];
          minimal_time.second = i;
        }
      }
    }
    checkedPositions.push_back(minimal_time.second);
    candidates.push_back(minimal_time);
  }
  // Select a random candidate
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(0, this->k_ - 1);
  int random = dis(gen);
  this->checkedPositions_.push_back(candidates[random].second);
  return candidates[random];
}
