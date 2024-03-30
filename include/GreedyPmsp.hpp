#ifndef __GREEDY_PMSP_HPP__
#define __GREEDY_PMSP_HPP__

#include "Pmsp.hpp"
#include "PmspProblem.hpp"
#include "PmspSolution.hpp"
#include <vector>

class GreedyPmsp : public Pmsp {
  public:
    GreedyPmsp(PmspProblem pmsp_problem);
    ~GreedyPmsp();
    // Solve method from Pmsp class
    PmspSolution Solve() override; 
  private:
    PmspProblem pmsp_problem_;
    // Method to select the initial jobs having in mind the processing time
    int* getInitialJobs();
    // Method to select the minimal time
    std::vector<std::pair<int, int>> selectMinimalTime(int* processing_times);
    // Method to select the optimus time for the machine
    std::pair<int, int> selectOptimusTime(int* selectRow, std::vector<int>& checkedPositions);
};

#endif // __GREEDY_PMSP_HPP__
