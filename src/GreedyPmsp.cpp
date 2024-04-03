#include "../include/GreedyPmsp.hpp"

#include <iostream>
#include <queue>

GreedyPmsp::GreedyPmsp(PmspProblem problem) : pmsp_problem_(problem) {
  inserted_ = new bool[pmsp_problem_.getJobs()];
  for (int i = 0; i < pmsp_problem_.getJobs(); i++) {
    inserted_[i] = false;
  }
  insertedValues_ = 0;
  actualMachine_ = 0;
}

PmspSolution GreedyPmsp::solve() {
  PmspSolution solution(pmsp_problem_);
  int* positionsToCheck = this->getInitialMachineValues();
  solution.setInitialMachineValues(positionsToCheck);
  std::queue<int> positions;
  for (int i = 0; i < pmsp_problem_.getMachines(); i++) {
    positions.push(positionsToCheck[i]);
  }
  while (insertedValues_ < pmsp_problem_.getJobs()) {
    insertTask(solution, positions);
    insertedValues_++;
  }
  solution.printSolution();
  return solution;
}

void GreedyPmsp::insertTask(PmspSolution& solution, std::queue<int>& positions) {
  // Print inserted values
  std::cout << "Inserted values: ";
  for (int i = 0; i < pmsp_problem_.getJobs(); i++) {
    std::cout << inserted_[i] << " ";
  }
  std::cout << std::endl;
  solution.setGreedyTask(positions, this->inserted_); 
  std::cout << "Post, inserted values: ";  
  for (int i = 0; i < pmsp_problem_.getJobs(); i++) {
    std::cout << inserted_[i] << " ";
  }
  std::cout << std::endl;
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
    values[j] = minIndex;
  }
  return values;
}
