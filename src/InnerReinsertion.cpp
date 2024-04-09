#include "../include/InnerReinsertion.hpp"

PmspSolution InnerReinsertion::getBestNeighbour(const PmspSolution& solution) {
  PmspSolution bestNeighbour = solution.getCopy();
  for (int i = 0; i < bestNeighbour.getMachineSize(); i++) {
    for (int j = 0; j < bestNeighbour.getSizeOfMachine(i); j++) {
      for (int k = 0; k < bestNeighbour.getSizeOfMachine(i); k++) {
        if (j != k) {
          PmspSolution neighbour = bestNeighbour.getCopy();
          reinsert(neighbour, i, j, k);
          if (neighbour.calculateTct() < bestNeighbour.calculateTct()) {
            bestNeighbour = neighbour;
          }
        }
      }
    }
  }
  return bestNeighbour;
}

void InnerReinsertion::reinsert(PmspSolution& solution, int i, int j, int machine) {
  // Reinsertar la tarea i en la posición j de la máquina machine
  int task = solution.getTasks()[machine][i];
  solution.insertValue(machine, j, task);
}