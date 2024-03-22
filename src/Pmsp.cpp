#include "../include/Pmsp.hpp"

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


