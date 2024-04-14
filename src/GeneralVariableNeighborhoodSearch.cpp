#include "../include/GeneralVariableNeighborhoodSearch.hpp"
#include "../include/GraspPmsp.hpp"

#include <iostream>

PmspSolution GeneralVariableNeighbourhoodSearch::execute(PmspProblem& pmspProblem) {
  int iterations = 0;
  const int maxIterations = 500;
  int noImprovement = 0;
  const int kMax = 6;
  PmspSolution bestSolution = GraspPmsp(pmspProblem).solve();
  VariableNeighbourDescent vnd;

  do {
    std::cout << "Iteration: " << iterations << std::endl;
    PmspSolution grasp = GraspPmsp(pmspProblem).solve();
    int k = 1;
    do {
      std::cout << "k: " << k << std::endl;
      PmspSolution firstSolution = grasp.shaking(k);
      PmspSolution secondSolution = vnd.execute(firstSolution);
      if (secondSolution.calculateTct() < bestSolution.calculateTct()) {
        bestSolution = secondSolution;
        noImprovement = 0;
      } else {
        k++;
      }
    } while (k < kMax);
    iterations++;
    if (bestSolution.calculateTct() == grasp.calculateTct()) {
      noImprovement++;
    }
    if (noImprovement == 50) break;
  }
  while (iterations < maxIterations);

  return bestSolution;
}