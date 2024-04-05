#include "../include/PmspProblem.hpp"
#include <iostream>

PmspProblem::PmspProblem(int jobs, int machines, int* processing_times, int** matrix) {
  jobs_ = jobs;
  machines_ = machines;
  // Hacer que processing_times_ sea processing_times con un 0 al principio
  processing_times_ = new int[jobs_ + 1];
  processing_times_[0] = 0;
  for (int i = 0; i < jobs; i++) {
    processing_times_[i + 1] = processing_times[i];
  }
  matrix_ = matrix;
  tasks_ = new int*[jobs_ + 1];
  for (int i = 0; i < jobs_ + 1; i++) {
    tasks_[i] = new int[jobs_];
  }
  for (int i = 0; i < jobs_ + 1; i++) {
    for (int j = 0; j < jobs_ + 1; j++) {
      if (i == j) continue;
      tasks_[i][j] = this->processing_times_[j] + this->matrix_[i][j];
    }
  }
}

PmspProblem::~PmspProblem() {
}

void PmspProblem::PrintMatrix() {
  for (int i = 0; i < jobs_ + 1; i++) {
    for (int j = 0; j < jobs_ + 1; j++) {
      std::cout << matrix_[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

void PmspProblem::PrintTasks() {
  for (int i = 0; i < jobs_ + 1; i++) {
    for (int j = 0; j < jobs_ + 1; j++) {
      std::cout << tasks_[i][j] << " ";
    }
    std::cout << std::endl;
  }
}
