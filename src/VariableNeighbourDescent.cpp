#include "../include/VariableNeighbourDescent.hpp"

#include <iostream>

VariableNeighbourDescent::VariableNeighbourDescent() {}

PmspSolution VariableNeighbourDescent::execute(PmspSolution& initialSolution) {
  PmspSolution bestSolution = initialSolution.getCopy();
  int n = 0;
  EnvironmentStructures* environment;
  while (n <= 3) {
    PmspSolution newSolution = bestSolution.getCopy();
    std::cout << "Case " <<  n << std::endl;
    switch(n) {
      case 0:
        environment = new OuterReinsertion();
        break;
      case 1:
        environment = new InnerReinsertion();
        break;
      case 2: 
        environment = new OuterExchange();
        break;
      case 3:
        environment = new InnerExchange();
        break;
      default:
        break;
    }
    newSolution = environment->getBestNeighbour(newSolution);
    if (newSolution.calculateTct() < bestSolution.calculateTct() && newSolution.calculateTct() > 0) {
      bestSolution = newSolution;
      n = 0;
    } else {
      n++;
    }
  }
  return bestSolution;
}