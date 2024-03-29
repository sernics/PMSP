#ifndef __GREEDY_PMSP_HPP__
#define __GREEDY_PMSP_HPP__

#include "Pmsp.hpp"
#include "PmspProblem.hpp"
#include <vector>

class GreedyPmsp : public Pmsp {
  public:
    GreedyPmsp(PmspProblem pmsp_problem);
    ~GreedyPmsp();
    void Solve() override;
    int* getInitialJobs();
    std::vector<std::pair<int, int>> selectMinimalTime(int* processing_times);
  private:
    PmspProblem pmsp_problem_;
};

#endif // __GREEDY_PMSP_HPP__
