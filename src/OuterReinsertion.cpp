#include "../include/OuterReinsertion.hpp"

#include <iostream>

PmspSolution OuterReinsertion::getBestNeighbour(const PmspSolution& solution) {
  PmspSolution bestNeighbour = solution.getCopy();

  for (int machineI = 0; machineI < solution.getMachineSize(); machineI++) {
    for (int machineJ = machineI + 1; machineJ < solution.getMachineSize(); machineJ++) {
      if (machineI == machineJ) {
        continue;
      }
      for (int i = 0; i < solution.getSizeOfMachine(machineI); i++) {
        for (int j = 0; j < solution.getSizeOfMachine(machineJ); j++) {
          PmspSolution neighbour = solution.getCopy();
          reinsert(neighbour, i, j, machineI, machineJ);
          if (neighbour.calculateTct() < bestNeighbour.calculateTct()) {
            bestNeighbour = neighbour;
          }
        }
      }
    }
  }

  return bestNeighbour;
}

void OuterReinsertion::reinsert(PmspSolution& solution, int i, int j, int machine1, int machine2) {
  int job = solution.getMachines()[machine1][i];
  solution.insertValue(machine2, job, j);
}