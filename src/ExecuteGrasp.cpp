#include "../include/ExecuteGrasp.hpp"
#include <iostream>

ExecuteGrasp::ExecuteGrasp(PmspProblem pmsp_problem) {
  pmsp_problem_ = pmsp_problem;
}

ExecuteGrasp::~ExecuteGrasp() {
}

PmspSolution ExecuteGrasp::Execute() {
  // Hacer que se ejecute grasp 100 veces y coger el menor tct
  int best_tct = 9999999;
  PmspSolution best_solution(pmsp_problem_);
  for (int i = 0; i < 100; i++) {
    GraspPmsp* grasp = new GraspPmsp(pmsp_problem_);
    PmspSolution solution = grasp->Solve();
    int tct = solution.calculateTCT();
    if (tct < best_tct) {
      best_tct = tct;
      best_solution = solution;
    }
  }
  return best_solution;
}