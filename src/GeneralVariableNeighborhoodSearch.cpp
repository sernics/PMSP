#include "../include/GeneralVariableNeighborhoodSearch.hpp"
#include "../include/GraspPmsp.hpp"

#include <iostream>

PmspSolution GeneralVariableNeighbourhoodSearch::execute(PmspProblem& pmspProblem, const int maxIterations) {
  int iterations = 0;
  int noImprovement = 0;
  PmspSolution bestSolution = GraspPmsp(pmspProblem).solve();
  do {
    std::cout << "Iterations " << iterations << std::endl;
    PmspSolution grasp = this->executeGVNS(pmspProblem);
    iterations++;
    if (grasp.calculateTct() < bestSolution.calculateTct()) {
      bestSolution = grasp;
      noImprovement = 0;
    } else if (bestSolution.calculateTct() == grasp.calculateTct()) {
      noImprovement++;
    }
    if (noImprovement == 50) break;
  } while (iterations < maxIterations);

  return bestSolution;
}

PmspSolution GeneralVariableNeighbourhoodSearch::executeGVNS(PmspProblem& pmspProblem) {
  VariableNeighbourDescent vnd;
  PmspSolution solution =  GraspPmsp(pmspProblem).solve();
  return vnd.execute(solution);
}