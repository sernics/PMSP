#include "../include/Pmsp.hpp"

Pmsp::Pmsp(PmspProblem problem) {
  problem_ = problem;
}

Pmsp::~Pmsp() {
  problem_.~PmspProblem();
}

