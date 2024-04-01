#include "../include/GraspPmsp.hpp"

#include "../include/Srv.hpp"

GraspPmsp::GraspPmsp(PmspProblem pmsp_problem) : GreedyPmsp(pmsp_problem) {}

GraspPmsp::~GraspPmsp() {}

std::pair<int, int> GraspPmsp::selectOptimusTime(int* selectRow, std::vector<int>& checkedPositions) {
  Srv srv(3, checkedPositions);
  return srv.selectOptimusTime(selectRow);
}
