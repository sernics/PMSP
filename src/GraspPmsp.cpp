#include "../include/GraspPmsp.hpp"

#include "../include/Srv.hpp"
#include <iostream>

GraspPmsp::GraspPmsp(PmspProblem pmsp_problem) : GreedyPmsp(pmsp_problem) {
  pmsp_problem_ = pmsp_problem;
}

GraspPmsp::~GraspPmsp() {}

std::pair<int, int> GraspPmsp::selectOptimusTime(int* selectRow, std::vector<int>& checkedPositions) {
  Srv srv(3, checkedPositions, pmsp_problem_);
  std::pair<int, int> result = srv.selectOptimusTime(selectRow);
  return result;
}
