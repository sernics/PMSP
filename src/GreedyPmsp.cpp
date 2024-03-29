#include "../include/GreedyPmsp.hpp"
#include <iostream>
#include <algorithm>

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
}

int* GreedyPmsp::getInitialJobs() {
  int* result = new int[pmsp_problem_.getMachines()];
  int* processingTimes = this->pmsp_problem_.getProcessingTimes();
  // Sort processingTimes
  std::sort(processingTimes, processingTimes + pmsp_problem_.getJobs());
  for (int i = 0; i < pmsp_problem_.getMachines(); i++) {
    result[i] = processingTimes[i];
  }
  return result;
}
