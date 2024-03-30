#include "../include/GreedyPmsp.hpp"
#include <vector>

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
  // Sort the checked positions
  std::sort(checkedPositions.begin(), checkedPositions.end());
  PmspSolution solution(this->pmsp_problem_);
  solution.pushInitialSolution(checkedPositions);
  int** setup = this->pmsp_problem_.getSetup();
  while (int(checkedPositions.size()) < this->pmsp_problem_.getJobs()) {
    for (int i = 0; i < this->pmsp_problem_.getMachines(); i++) {
      std::tuple<int, int> nextOptimal = this->selectOptimusTime(setup[solution.getLastElement(i)], checkedPositions);
      solution.pushIndex(i, std::get<1>(nextOptimal));
      checkedPositions.push_back(std::get<1>(nextOptimal));
    }
  }
  return solution;
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

std::pair<int, int> GreedyPmsp::selectOptimusTime(int* selectRow, std::vector<int>& checkedPositions) {
  // Seleccionar el valor mínimo de la fila y guardar una tupla con el valor y la posición
  std::pair<int, int> minimal_time = std::make_pair(selectRow[0], 0);
  for (int i = 1; i < this->pmsp_problem_.getJobs() + 1; i++) {
    if (selectRow[i] < minimal_time.first) {
      // Asegurate de que el indice no esté en checkedPositions
      if (std::find(checkedPositions.begin(), checkedPositions.end(), i) == checkedPositions.end()) {
        minimal_time = std::make_pair(selectRow[i], i);
      }
    }
  }
  return minimal_time;
}
