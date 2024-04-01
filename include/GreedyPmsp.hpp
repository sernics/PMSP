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
  protected:
    // Method to obtein the initial jobs having add the processing times and the setup times
    int* getInitialJobs();
    // Method to select the minimal time from the getInitialJobs method
    std::vector<std::pair<int, int>> selectMinimalTime(int* processing_times);
    // Method to select the optimus time for the machine
    virtual std::pair<int, int> selectOptimusTime(int* selectRow, std::vector<int>& checkedPositions);
  private:
    PmspProblem pmsp_problem_;
};

#endif // __GREEDY_PMSP_HPP__
