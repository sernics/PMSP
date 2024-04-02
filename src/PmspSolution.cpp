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
    std::cout << "Machine " << i << ": ";
    for (size_t j = 0; j < solution_[i].size(); j++) {
      std::cout << solution_[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

int PmspSolution::calculateTCT() {
  // Calculate the TCT
  int* processing_times = pmsp_problem_.getProcessingTimes();
  int** setup = pmsp_problem_.getSetup();
  int tct = 0;
  for (int i = 0; i < pmsp_problem_.getMachines(); i++) {
    int time = 0;
    for (size_t j = 0; j < solution_[i].size(); j++) {
      time += processing_times[solution_[i][j]];
      if (j != 0) {
        time += setup[solution_[i][j - 1]][solution_[i][j]];
      }
    }
    if (time > tct) {
      tct = time;
    }
  }
  return tct;
}
