#include "../include/GreedyPmsp.hpp"

GreedyPmsp::GreedyPmsp(PmspProblem problem) : pmsp_problem_(problem) {
  inserted_ = new bool[pmsp_problem_.getJobs() + 1];
  for (int i = 0; i < pmsp_problem_.getJobs(); i++) {
    inserted_[i] = false;
  }
  inserted_[0] = true;
  insertedValues_ = 1;
  actualMachine_ = 0;
}

PmspSolution GreedyPmsp::solve() {
  PmspSolution solution(pmsp_problem_);
  int* positionsToCheck = this->getInitialMachineValues();
  solution.setInitialMachineValues(positionsToCheck);
  int index = 0;
  while (insertedValues_ < pmsp_problem_.getJobs()) {
    insertTask(solution, index);
    index++;
    if (index > this->pmsp_problem_.getMachines()) {
      index = 0;
    }
  }
  return solution;
}

void GreedyPmsp::insertTask(PmspSolution& solution, int index) {
  solution.setGreedyTask(index, this->inserted_); 
  insertedValues_++;
  return;
}

int* GreedyPmsp::getInitialMachineValues() {
  int* values = new int[pmsp_problem_.getMachines()];
  // Select the lowest values of pmsp_problem_.getTasks()
  for (int j = 0; j < pmsp_problem_.getMachines(); j++) {
    int min = 99999999;
    int minIndex = -1;
    for (int i = 0; i < pmsp_problem_.getJobs(); i++) {
      if (!inserted_[i]) {
        if (pmsp_problem_.getTasks()[0][i] < min) {
          min = pmsp_problem_.getTasks()[0][i];
          minIndex = i;
        }
      }
    }
    inserted_[minIndex] = true;
    insertedValues_++;
    values[j] = minIndex;
  }
  return values;
}
