#include "../include/GeneralVariableNeighborhoodSearch.hpp"
#include "../include/GraspPmsp.hpp"

#include <iostream>

PmspSolution GeneralVariableNeighbourhoodSearch::execute(PmspProblem& pmspProblem, const int maxIterations) {
  int iterations = 0;
  int noImprovement = 0;
  PmspSolution bestSolution = GraspPmsp(pmspProblem).solve();
  do {
    PmspSolution grasp = this->executeGVNS(pmspProblem);
    iterations++;
    if (bestSolution.calculateTct() == grasp.calculateTct()) {
      noImprovement++;
    }
    if (noImprovement == 50) break;
  } while (iterations < maxIterations);

  return bestSolution;
}

PmspSolution GeneralVariableNeighbourhoodSearch::executeGVNS(PmspProblem& pmspProblem) {
  int k = 1;
  const int kMax = 6;
  PmspSolution bestSolution = GraspPmsp(pmspProblem).solve();
  PmspSolution grasp = bestSolution.getCopy();
  VariableNeighbourDescent vnd;
  do {
    PmspSolution firstSolution = grasp.shaking(k);
    PmspSolution secondSolution = vnd.execute(firstSolution);
    if (secondSolution.calculateTct() < bestSolution.calculateTct()) {
      bestSolution = secondSolution;
    } else {
      k++;
    }
  } while (k < kMax);
  return bestSolution;
}