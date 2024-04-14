#include "../include/ExecuteGrasp.hpp"
#include "../include/Pmsp.hpp"
#include "../include/GraspPmsp.hpp"

#include <iostream>

ExecuteGrasp::ExecuteGrasp(PmspProblem problem) : pmspProblem_(problem) {}

PmspSolution ExecuteGrasp::execute() {
  Pmsp* pmsp = new GraspPmsp(pmspProblem_);
  PmspSolution solution = pmsp->solve();
  for (int i = 0; i < 1000; i++) {
    Pmsp* pmsp = new GraspPmsp(pmspProblem_);
    PmspSolution newSolution = pmsp->solve();
    if (newSolution.calculateTct() < solution.calculateTct()) {
      solution = newSolution;
    }    
  }
  return solution;
}