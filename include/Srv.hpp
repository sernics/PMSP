#ifndef __SRV_HPP__
#define __SRV_HPP__

#include "PmspProblem.hpp"
#include <vector>

class Srv {
  public:
    Srv(int k, std::vector<int>& checkedPositions, PmspProblem pmsp_problem);
    ~Srv();
    // Method to select k optimus times for the machine that are not in the checkedPositions vector
    // and select one of them randomly
    std::pair<int, int> selectOptimusTime(int* selectRow);
  private:
    int k_;
    std::vector<int> checkedPositions_;
    PmspProblem pmsp_problem_;
};

#endif // __SRV_HPP__
