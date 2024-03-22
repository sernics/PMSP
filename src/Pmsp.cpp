#include "../include/Pmsp.hpp"
#include <iostream>

Pmsp::Pmsp(int jobs, int machines, int* processing_times, int** matrix) {
  jobs_ = jobs;
  machines_ = machines;
  processing_times_ = processing_times;
  matrix_ = matrix;
}

Pmsp::~Pmsp() {
  delete[] processing_times_;
  for (int i = 0; i < jobs_ + 1; i++) {
    delete[] matrix_[i];
  }
  delete[] matrix_;
}

void Pmsp::PrintMatrix() {
  for (int i = 0; i < jobs_ + 1; i++) {
    for (int j = 0; j < jobs_ + 1; j++) {
      std::cout << matrix_[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

