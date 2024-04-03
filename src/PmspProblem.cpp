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
  tasks_ = new int*[jobs_];
  for (int i = 0; i < jobs_; i++) {
    tasks_[i] = new int[jobs_];
  }
  for (int i = 0; i < jobs_; i++) {
    for (int j = 0; j < jobs_; j++) {
      if (i == j) continue;
      tasks_[i][j] = this->processing_times_[j] + this->matrix_[i][j];
    }
  }
  // Print processing times
  std::cout << "Processing times: ";
  for (int i = 0; i < jobs_; i++) {
    std::cout << processing_times_[i] << ",";
  }
  std::cout << std::endl;
  // Print setup times
  std::cout << "Setup times: " << std::endl;
  for (int i = 0; i < jobs_ + 1; i++) {
    for (int j = 0; j < jobs_ + 1; j++) {
      std::cout << matrix_[i][j] << ",";
    }
    std::cout << std::endl;
  }
  // Print tasks
  std::cout << "Tasks: " << std::endl;
  for (int i = 0; i < jobs_; i++) {
    for (int j = 0; j < jobs_; j++) {
      std::cout << tasks_[i][j] << ",";
    }
    std::cout << std::endl;
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
