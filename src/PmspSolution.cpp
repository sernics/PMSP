#include "../include/PmspSolution.hpp"

#include <iostream>

PmspSolution::PmspSolution(PmspProblem problem) {
  this->jobs_ = problem.getJobs();
  this->machines_ = new int*[problem.getMachines()];
  this->sizeOfMachines_ = problem.getMachines();
  this->tasks_ = problem.getTasks();
  this->sizeOfMachineTasks_ = new int[this->sizeOfMachines_];
  this->tct_values_ = new int[this->sizeOfMachines_];
}

PmspSolution::~PmspSolution() {}

int PmspSolution::tct(int machine) {
  int result = 0;
  int* tasks = new int[this->sizeOfMachineTasks_[machine]];
  tasks[0] = this->tasks_[0][machines_[machine][0]];
  for (int i = 1; i < this->sizeOfMachineTasks_[machine]; i++) {
    tasks[i] = this->tasks_[machines_[machine][i - 1]][machines_[machine][i]];
  }
  for (int i = 0; i < this->sizeOfMachineTasks_[machine]; i++) {
    result += tasks[i] * (this->sizeOfMachineTasks_[machine] - i);
  }
  this->tct_values_[machine] = result;
  this->machineIndex_ = 0;
  return result;
}

int PmspSolution::calculateTct() {
  int result = 0;
  for (int i = 0; i < this->sizeOfMachines_; i++) {
    result += this->tct_values_[i];
  }
  return result;
}

void PmspSolution::setInitialMachineValues(int* values) {
  // Para cada máquina colocar en la primera posición el valor de values
  for (int i = 0; i < this->sizeOfMachines_; i++) {
    this->machines_[i] = new int[this->sizeOfMachineTasks_[i]];
    this->machines_[i][0] = values[i];
    this->sizeOfMachineTasks_[i] = 1;
    this->tct_values_[i] = this->tct(i);
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

void PmspSolution::insertValue(int machine, int value, int position = -1) {
  if (position == -1) {
    position = this->sizeOfMachineTasks_[machine];
  }
  int* newMachine = new int[this->sizeOfMachineTasks_[machine] + 1];
  for (int i = 0; i < position; i++) {
    newMachine[i] = this->machines_[machine][i];
  }
  newMachine[position] = value;
  for (int i = position + 1; i < this->sizeOfMachineTasks_[machine] + 1; i++) {
    newMachine[i] = this->machines_[machine][i - 1];
  }
  this->machines_[machine] = newMachine;
  this->sizeOfMachineTasks_[machine]++;
  this->tct_values_[machine] = this->tct(machine);
}

void PmspSolution::setGreedyTask(int index, bool* inserted) {
  this->machineIndex_++;
  int* tasks = this->tasks_[index];
  int min = 999999;
  int taskIndex = -1;
  for (int i = 0; i < this->jobs_; i++) {
    if (!inserted[i]) {
      if (tasks[i] < min) {
        min = tasks[i];
        taskIndex = i;
      }
    }
  }
  inserted[taskIndex] = true;
  this->insertValue(index, taskIndex);
  return;
}

PmspSolution PmspSolution::operator=(const PmspSolution& solution) {
  this->machines_ = solution.machines_;
  this->sizeOfMachines_ = solution.sizeOfMachines_;
  this->tasks_ = solution.tasks_;
  this->sizeOfMachineTasks_ = solution.sizeOfMachineTasks_;
  return *this;
}
