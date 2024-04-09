#include "../include/InterExchange.hpp"

#include <iostream>

PmspSolution InterExchange::getBestNeighbour(const PmspSolution& solution) {
  PmspSolution bestNeighbour = solution.getCopy();
  for (int i = 0; i < solution.getMachineSize(); i++) {
    for (int j = 0; j < solution.getMachineSize(); j++) {
      if (i == j) {
        continue;
      }
      for (int k = 0; k < solution.getSizeOfMachine(i); k++) {
        for (int l = 0; l < solution.getSizeOfMachine(j); l++) {
          PmspSolution neighbour = solution.getCopy();
          exchange(neighbour, i, k, j, l);
          if (neighbour.calculateTct() < bestNeighbour.calculateTct()) {
            bestNeighbour = neighbour;
          }
        }
      }
    }
  }
  return bestNeighbour;
}

void InterExchange::exchange(PmspSolution &solution, int i, int j, int machine1, int machine2) {
  // move value i form machine1 to machine2 in position j
  solution = solution.exchange(i, j, machine1, machine2);
}