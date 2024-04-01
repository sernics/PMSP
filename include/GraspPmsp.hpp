#ifndef __GRASP_PMSP_HPP__
#define __GRASP_PMSP_HPP__

#include "GreedyPmsp.hpp"
#include "PmspProblem.hpp"
#include <vector>

class GraspPmsp : public GreedyPmsp {
  public:
    GraspPmsp(PmspProblem pmsp_problem);
    ~GraspPmsp();
    // Method to select the optimus time for the machine
    std::pair<int, int> selectOptimusTime(int* selectRow, std::vector<int>& checkedPositions) override;
  private:  
};

#endif // __GRASP_PMSP_HPP__
