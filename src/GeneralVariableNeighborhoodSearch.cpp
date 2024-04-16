#include "../include/GeneralVariableNeighborhoodSearch.hpp"
#include "../include/GraspPmsp.hpp"

#include <iostream>

PmspSolution GeneralVariableNeighbourhoodSearch::execute(PmspProblem& pmspProblem, const int maxIterations) {
  int iterations = 0;
  int noImprovement = 0;
  PmspSolution bestSolution = GraspPmsp(pmspProblem).solve();
  do {
    PmspSolution grasp = this->executeGVNS(pmspProblem);
    std::cout << "Iteration: " << iterations << " TCT: " << bestSolution.calculateTct() << std::endl;
    iterations++;
    if (grasp.calculateTct() < bestSolution.calculateTct()) {
      bestSolution = grasp;
      noImprovement = 0;
    } else {
      noImprovement++;
    }
    if (noImprovement == 100) break;
  } while (iterations < maxIterations);

  return bestSolution;
}

PmspSolution GeneralVariableNeighbourhoodSearch::executeGVNS(PmspProblem& pmspProblem) {
  VariableNeighbourDescent vnd;
  PmspSolution bestSolution =  GraspPmsp(pmspProblem).solve();
  int k = 1;
  const int kMax = 6;
  do {
    PmspSolution newSolution = bestSolution.shaking(k);

    PmspSolution vndSolution = vnd.execute(newSolution);

    if (vndSolution.calculateTct() < bestSolution.calculateTct()) {
      bestSolution = vndSolution;
      k = 1;
    } else {
      k++;
    }
  } while (k < kMax);
  return vnd.execute(bestSolution);
}