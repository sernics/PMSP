#include "../include/PmspSolution.hpp"
#include <iostream>

PmspSolution::PmspSolution(PmspProblem& pmsp_problem) {
  pmsp_problem_ = pmsp_problem;
}

PmspSolution::~PmspSolution() {
}

void PmspSolution::pushInitialSolution(std::vector<int>& solution) {
  // Quiero que se asigne cada valor de solution a cada fila de solution_
  solution_.resize(pmsp_problem_.getMachines());
  for (int i = 0; i < pmsp_problem_.getMachines(); i++) {
    solution_[i].push_back(solution[i]);
  }
}

void PmspSolution::pushIndex(int i, int value) {
  solution_[i].push_back(value);
}

int PmspSolution::getLastElement(int i) {
  return solution_[i].back();
}

void PmspSolution::PrintSolution() {
  for (int i = 0; i < pmsp_problem_.getMachines(); i++) {
    for (int j = 0; j < pmsp_problem_.getJobs(); j++) {
      std::cout << solution_[i][j] << " ";
    }
    std::cout << std::endl;
  }
}
