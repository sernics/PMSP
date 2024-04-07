#ifndef __EXECUTE_GRASP_HPP__
#define __EXECUTE_GRASP_HPP__

#include "GraspPmsp.hpp"
#include "PmspProblem.hpp"
#include "PmspSolution.hpp"

class ExecuteGrasp {
  public:
    ExecuteGrasp() = default;
    ExecuteGrasp(PmspProblem problem);
    PmspSolution execute();
  private:
    PmspProblem pmspProblem_;
};

#endif // __EXECUTE_GRASP_HPP__