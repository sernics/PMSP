#include "../include/OuterReinsertion.hpp"

#include <iostream>

PmspSolution OuterReinsertion::getBestNeighbour(const PmspSolution& solution) {
  PmspSolution bestNeighbour = solution.getCopy();

  // Reinsertion for each job in each machine in each position of the machine. Unless if are the same machine.
  for (int i = 0; i < solution.getMachineSize(); i++) {
    for (int j = 0; j < solution.getMachineSize(); j++) {
      for (int k = 0; k < solution.getMachineSize(); k++) {
        for (int l = 0; l < solution.getMachineSize(); l++) {
          if (i != k) {
            PmspSolution neighbour = solution.getCopy();
            reinsert(neighbour, i, j, k, l);
            if (neighbour.calculateTct() < bestNeighbour.calculateTct()) {
              bestNeighbour = neighbour;
              return bestNeighbour;
            }
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