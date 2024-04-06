#ifndef __GREEDY_PMSP_HPP__
#define __GREEDY_PMSP_HPP__

#include "Pmsp.hpp"
#include "PmspProblem.hpp"
#include "PmspSolution.hpp"

class GreedyPmsp : public Pmsp {
  public:
    GreedyPmsp() = default;
    GreedyPmsp(PmspProblem problem);
    PmspSolution solve() override;
  protected:
    virtual void insertTask(PmspSolution& solution);
  private:
    PmspProblem pmsp_problem_;
    bool* inserted_;
    int insertedValues_;
    int actualMachine_;

    int* getInitialMachineValues();
};

#endif // __GREEDY_PMSP_HPP__
