#include "../include/PmspSolution.hpp"

#include <iostream>

PmspSolution::PmspSolution(PmspProblem problem) {
  this->machines_ = new int*[problem.getMachines()];
  this->sizeOfMachines_ = problem.getMachines();
  this->tasks_ = problem.getTasks();
  this->sizeOfMachineTasks_ = new int[this->sizeOfMachines_];
}

PmspSolution::~PmspSolution() {}

int PmspSolution::tct(int machine) {
  int result = 0;
  for (int i = 0; i < this->sizeOfMachineTasks_[machine]; i++) {
    result += (this->sizeOfMachineTasks_[machine] - i) * this->tasks_[this->machines_[machine][i]][i];  
  }
  return result;
}

int PmspSolution::calculateTct() {
  int result = 0;
  for (int i = 0; i < this->sizeOfMachines_; i++) {
    result += this->tct(i);
  }
  return result;
}

void PmspSolution::setInitialMachineValues(int* values) {
  // Para cada máquina colocar en la primera posición el valor de values
  for (int i = 0; i < this->sizeOfMachines_; i++) {
    this->machines_[i] = new int[this->sizeOfMachineTasks_[i]];
    this->machines_[i][0] = values[i];
    this->sizeOfMachineTasks_[i] = 1;
  }
}

void PmspSolution::printSolution() {
  for (int i = 0; i < this->sizeOfMachines_; i++) {
    std::cout << "Machine " << i << ": ";
    for (int j = 0; j < this->sizeOfMachineTasks_[i]; j++) {
      std::cout << this->machines_[i][j] << " ";
    }
    std::cout << std::endl;
  }
}


void PmspSolution::setGreedyTask(std::queue<int>& positions, bool* inserted) {
  // Actualizar machines_[0], incrementar su valor en 1 y añadir un 100 al final
  int* newMachine = new int[this->sizeOfMachineTasks_[0] + 1];
  for (int i = 0; i < this->sizeOfMachineTasks_[0]; i++) {
    newMachine[i] = this->machines_[0][i];
  }
  newMachine[this->sizeOfMachineTasks_[0]] = 100;
  machines_[0] = newMachine;
  this->sizeOfMachineTasks_[0]++;
  inserted[1] = true;
  return;
}
