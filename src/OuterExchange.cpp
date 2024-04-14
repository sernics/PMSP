#include "../include/OuterExchange.hpp"

#include <iostream>

PmspSolution OuterExchange::getBestNeighbour(const PmspSolution& solution) {
  PmspSolution bestNeighbour = solution.getCopy();

  for (int machineI = 0; machineI < solution.getMachineSize(); machineI++) {
    for (int machineJ = machineI + 1; machineJ < solution.getMachineSize(); machineJ++) {
      if (machineI == machineJ) {
        continue;
      }
      for (int i = 0; i < solution.getSizeOfMachine(machineI); i++) {
        for (int j = 0; j < solution.getSizeOfMachine(machineJ); j++) {
          PmspSolution neighbour = solution.getCopy();
          exchange(neighbour, i, j, machineI, machineJ);
          if (neighbour.calculateTct() < bestNeighbour.calculateTct()) {
            bestNeighbour = neighbour;
          }
        }
      }
    }
  }

  return bestNeighbour;
}

void OuterExchange::exchange(PmspSolution &solution, int i, int j, int machine1, int machine2) {
  solution = solution.exchange(i, j, machine1, machine2);
}