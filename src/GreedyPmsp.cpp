#include "../include/GreedyPmsp.hpp"
#include <iostream>

GreedyPmsp::GreedyPmsp(PmspProblem pmsp_problem) {
  pmsp_problem_ = pmsp_problem;
}

GreedyPmsp::~GreedyPmsp() {
}

void GreedyPmsp::Solve() {
  int* initialJobs = getInitialJobs();
  // Print initial jobs
  std::cout << "Initial jobs: ";
  for (int i = 0; i < pmsp_problem_.getMachines(); i++) {
    std::cout << initialJobs[i] << " ";
  }
  std::cout << std::endl;
}

int* GreedyPmsp::getInitialJobs() {
  int* result = new int[pmsp_problem_.getMachines()];
  for (int i = 0; i < pmsp_problem_.getMachines(); i++) {
    result[i] = 10;
  }
  return new int();
}
