#include "../include/InterReinsertion.hpp"

PmspSolution InterReinsertion::getBestNeighbour(const PmspSolution& solution) {
  PmspSolution bestNeighbour = solution.getCopy();
  return bestNeighbour;
}

void InterReinsertion::reinsert(PmspSolution& solution, int i, int j, int machine1, int machine2) {
  int task = solution.getTasks()[machine1][i];
  solution.insertValue(machine2, task, j);
}