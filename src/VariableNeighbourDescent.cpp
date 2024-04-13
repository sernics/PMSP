#include "../include/VariableNeighbourDescent.hpp"

#include <iostream>

VariableNeighbourDescent::VariableNeighbourDescent() {}

PmspSolution VariableNeighbourDescent::execute(PmspSolution& initialSolution) {
  PmspSolution bestSolution = initialSolution.getCopy();
  int n = 0;
  EnvironmentStructures* environment;
  while (n <= 3) {
    PmspSolution newSolution = bestSolution.getCopy();
    std::cout << "Case: " << n << "\n";
    switch(n) {
      case 0:
        environment = new InnerExchange();
        break;
      case 1:
        environment = new InnerExchange();
        break;
      case 2: 
        environment = new InnerExchange();
        break;
      case 3:
        environment = new InnerExchange();
        break;
      default:
        break;
    }
    newSolution = environment->getBestNeighbour(newSolution);
    newSolution.printSolution();
    std::cout << newSolution.calculateTct() << std::endl;
    if (newSolution.calculateTct() < bestSolution.calculateTct()) {
      bestSolution = newSolution;
      n = 0;
    } else {
      n++;
    }
  }
  return bestSolution;
}