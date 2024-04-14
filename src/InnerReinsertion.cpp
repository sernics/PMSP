#include "../include/InnerReinsertion.hpp"

#include <iostream>

PmspSolution InnerReinsertion::getBestNeighbour(const PmspSolution& solution) {
  PmspSolution bestNeighbour = solution.getCopy();
  for (int machineI = 0; machineI < solution.getMachineSize(); machineI++) {
    for (int i = 0; i < solution.getSizeOfMachine(machineI); i++) {
      for (int j = 0; j < solution.getSizeOfMachine(machineI); j++) {
        if (i == j) {
          continue;
        }
        PmspSolution neighbour = solution.getCopy();
        reinsert(neighbour, i, j, machineI);
        if (neighbour.calculateTct() < bestNeighbour.calculateTct()) {
          bestNeighbour = neighbour;
        }
      }
    }
  }
  return bestNeighbour;
}

void InnerReinsertion::reinsert(PmspSolution& solution, int i, int j, int machine) {
  int job = solution.getMachines()[machine][i];
  solution.insertValue(machine, job, j);
}