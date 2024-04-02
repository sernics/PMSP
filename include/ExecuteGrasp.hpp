#include "GraspPmsp.hpp"

class ExecuteGrasp {
 public:
  ExecuteGrasp(PmspProblem pmsp_problem);
  ~ExecuteGrasp();
  PmspSolution Execute();
 private:
  PmspProblem pmsp_problem_;
};