#include "../include/PmspSolution.hpp"

#include <iostream>
#include <random>

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
  delete[] tasks;
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

void PmspSolution::deleteValue(int machine, int position) {
  int* newMachine = new int[this->sizeOfMachineTasks_[machine] - 1];
  for (int i = 0; i < position; i++) {
    newMachine[i] = this->machines_[machine][i];
  }
  for (int i = position; i < this->sizeOfMachineTasks_[machine] - 1; i++) {
    newMachine[i] = this->machines_[machine][i + 1];
  }
  this->machines_[machine] = newMachine;
  this->sizeOfMachineTasks_[machine]--;
  this->tct_values_[machine] = this->tct(machine);
}

void PmspSolution::setGreedyTask(bool* inserted) {
  int min = 99999999;
  int minIndex = -1;
  int machine = -1;
  for (int i = 0; i < this->sizeOfMachines_; i++) {
    for (int j = 1; j < this->jobs_ + 1; j++) {
      if (!inserted[j]) {
        PmspSolution solution = *this;
        solution.insertValue(i, j);
        if (solution.tct(i) < min) {
          min = solution.tct(i);
          minIndex = j;
          machine = i;
        }
        solution.deleteValue(i, solution.sizeOfMachineTasks_[i] - 1);
      }
    }
  }
  // std::cout << "Inserting " << minIndex << " in machine " << machine << std::endl;
  this->insertValue(machine, minIndex);
  inserted[minIndex] = true;
}

void PmspSolution::setGraspTask(bool* inserted) {
  const int K = 3; // Number of values to select
  int min = 99999999;
  int minIndex = -1;
  int machine = -1;
  for (int i = 0; i < this->sizeOfMachines_; i++) {
    std::vector<int> candidates;
    for (int kValue = 0; kValue < K; kValue++) {
      int selectMin = 99999999;
      int selectMinIndex = -1;
      for (int j = 1; j < this->jobs_ + 1; j++) {
        if (!inserted[j]) {
          // If !isInCandidates
          if (std::find(candidates.begin(), candidates.end(), j) == candidates.end()) {
            if (this->tasks_[this->machines_[i][this->sizeOfMachineTasks_[i] - 1]][j] < selectMin) {
              selectMin = this->tasks_[this->machines_[i][this->sizeOfMachineTasks_[i] - 1]][j];
              selectMinIndex = j;
            }
          }
        }
      }
      if (selectMinIndex != -1) {
        candidates.push_back(selectMinIndex);
      }
    }
    // Seleccionar al azar uno de los candidatos
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, candidates.size() - 1);
    int randomIndex = dis(gen);
    int randomValue = candidates[randomIndex];
    PmspSolution solution = *this;
    solution.insertValue(i, randomValue);
    if (solution.tct(i) < min) {
      min = solution.tct(i);
      minIndex = randomValue;
      machine = i;
    }
    solution.deleteValue(i, solution.sizeOfMachineTasks_[i] - 1);
  }
  this->insertValue(machine, minIndex);
  inserted[minIndex] = true;
}

void PmspSolution::swapValues(int machine1, int position1, int machine2, int position2) {
  std::swap(this->machines_[machine1][position1], this->machines_[machine2][position2]);
  if (machine1 != machine2) {
    this->tct(machine1);
    this->tct(machine2);
  } else {
    this->tct(machine1);
  }
}