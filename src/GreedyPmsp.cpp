#include "../include/GreedyPmsp.hpp"
#include <iostream>
#include <vector>

GreedyPmsp::GreedyPmsp(PmspProblem pmsp_problem) {
  pmsp_problem_ = pmsp_problem;
}

GreedyPmsp::~GreedyPmsp() {
}

void GreedyPmsp::Solve() {
  int* initial = getInitialJobs(); 
  std::vector<std::pair<int, int>> minimal_time = selectMinimalTime(initial);
  std::vector<int> checkedPositions;
  for (int i = 0; i < this->pmsp_problem_.getMachines(); i++) {
    checkedPositions.push_back(minimal_time[i].second);
  }
  for (size_t i = 0; i < checkedPositions.size(); i++) {
    std::cout << checkedPositions[i] << " ";
  }
  std::cout << std::endl;
}

int* GreedyPmsp::getInitialJobs() {
  // Guardar en un array el valor de this->pmsp_problem_.getProcessingTimes que es un array
  // pero introducir un 0 en la primera posición
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
  // Guardar en un vector los tiempos de procesamiento con su índice
  std::vector<std::pair<int, int>> processing_times_vector;
  for (int i = 0; i < this->pmsp_problem_.getJobs() + 1; i++) {
    processing_times_vector.push_back(std::make_pair(processing_times[i], i));
  }
  // Ordenar el vector
  std::sort(processing_times_vector.begin(), processing_times_vector.end());
  std::vector<std::pair<int, int>> minimal_time;
  for (int i = 0; i < this->pmsp_problem_.getMachines(); i++) {
    minimal_time.push_back(processing_times_vector[i]);
  }
  return processing_times_vector;
}

