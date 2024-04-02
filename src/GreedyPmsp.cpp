#include "../include/GreedyPmsp.hpp"
#include <vector>
#include <iostream>

GreedyPmsp::GreedyPmsp(PmspProblem pmsp_problem) {
  pmsp_problem_ = pmsp_problem;
}

GreedyPmsp::~GreedyPmsp() {
}

PmspSolution GreedyPmsp::Solve() {
  int* initial = getInitialJobs(); 
  std::vector<std::pair<int, int>> minimal_time = selectMinimalTime(initial);
  std::vector<int> checkedPositions;
  // second is the index of the job
  for (int i = 0; i < this->pmsp_problem_.getMachines(); i++) {
    checkedPositions.push_back(minimal_time[i].second);
  }
  PmspSolution solution(this->pmsp_problem_);
  solution.pushInitialSolution(checkedPositions);
  int** setup = this->pmsp_problem_.getSetup();
  while (int(checkedPositions.size()) < this->pmsp_problem_.getJobs()) {
    for (int i = 0; i < this->pmsp_problem_.getMachines(); i++) {
      if (int(checkedPositions.size()) == this->pmsp_problem_.getJobs()) {
        break;
      }
      int* selectRow = setup[checkedPositions[i]];
      std::pair<int, int> optimus_time = selectOptimusTime(selectRow, checkedPositions);
      if (optimus_time.second != 0) {
        checkedPositions.push_back(optimus_time.second);
        solution.pushIndex(i, optimus_time.second);
      }
    }
  }
  return solution;
}

int* GreedyPmsp::getInitialJobs() {
  int* processing_times = new int[this->pmsp_problem_.getJobs() + 1];
  processing_times[0] = 0;
  for (int i = 1; i <= this->pmsp_problem_.getJobs(); i++) {
    processing_times[i] = this->pmsp_problem_.getProcessingTimes()[i - 1];
  }
  int* setup = this->pmsp_problem_.getSetup()[0];
  for (int i = 0; i < this->pmsp_problem_.getJobs() + 1; i++) {
    processing_times[i] += setup[i];
  }
  return processing_times;
}

std::vector<std::pair<int, int>> GreedyPmsp::selectMinimalTime(int* processing_times) {
  std::vector<std::pair<int, int>> processing_times_vector;
  for (int i = 0; i < this->pmsp_problem_.getJobs() + 1; i++) {
    processing_times_vector.push_back(std::make_pair(processing_times[i], i));
  }
  // Sort the vector
  std::sort(processing_times_vector.begin(), processing_times_vector.end());
  std::vector<std::pair<int, int>> minimal_time;
  for (int i = 0; i < this->pmsp_problem_.getMachines(); i++) {
    minimal_time.push_back(processing_times_vector[i]);
  }
  return processing_times_vector;
}

std::pair<int, int> GreedyPmsp::selectOptimusTime(int* selectRow, std::vector<int>& checkedPositions) {
  std::pair<int, int> minimal_time = std::make_pair(9999999, 0);
  for (int i = 0; i < this->pmsp_problem_.getJobs(); i++) {
    if (selectRow[i] < minimal_time.first) {
      if (std::find(checkedPositions.begin(), checkedPositions.end(), i) == checkedPositions.end()) {
        minimal_time.first = selectRow[i];
        minimal_time.second = i;
      }
    }
  }
  return minimal_time;
}
