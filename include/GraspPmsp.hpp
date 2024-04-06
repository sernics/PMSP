#ifndef __GRASP_PMSP_HPP__
#define __GRASP_PMSP_HPP__

#include "GreedyPmsp.hpp"

class GraspPmsp : public GreedyPmsp {
  public:
    GraspPmsp() = default;
    GraspPmsp(PmspProblem problem);
  protected:
    void insertTask(PmspSolution& solution) override;
};

#endif // __GRASP_PMSP_HPP__
