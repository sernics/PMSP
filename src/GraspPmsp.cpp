#include "../include/GraspPmsp.hpp"

GraspPmsp::GraspPmsp(PmspProblem problem) : GreedyPmsp(problem) {}

void GraspPmsp::insertTask(PmspSolution& solution) {
  solution.setGraspTask(this->inserted_);
  return;
}
