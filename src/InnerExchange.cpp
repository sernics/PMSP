#include "../include/InnerExchange.hpp"

#include <iostream>

PmspSolution InnerExchange::getBestNeighbour(const PmspSolution& solution) {
  PmspSolution bestNeighbour = solution.getCopy();
  for (int i = 0; i < solution.getMachineSize(); i++) {
    for (int j = 0; j < solution.getSizeOfMachine(i); j++) {
      for (int k = j + 1; k < solution.getSizeOfMachine(i); k++) {
        PmspSolution neighbour = solution.getCopy();
        exchange(neighbour, i, j, k);
        if (neighbour.calculateTct() < bestNeighbour.calculateTct()) {
          bestNeighbour = neighbour;
        }
      }
    }
  }
  return bestNeighbour;
}

void InnerExchange::exchange(PmspSolution &solution, int machine, int position1, int position2) {
  solution.moveValue(machine, position1, position2);
}