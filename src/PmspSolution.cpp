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

int PmspSolution::tct(int machine) const {
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

int PmspSolution::calculateTct() const {
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

void PmspSolution::printSolution() const {
  for (int i = 0; i < this->sizeOfMachines_; i++) {
    std::cout << "Machine " << i << ": ";
    for (int j = 0; j < this->sizeOfMachineTasks_[i]; j++) {
      std::cout << this->machines_[i][j] << " ";
    }
    std::cout << "-> " << this->tct_values_[i] << std::endl;
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

// Swap position to positionResult and move the rest of the values
void PmspSolution::moveValue(int machine1, int position, int positionResult) {
  int value = this->machines_[machine1][position];
  if (position < positionResult) {
    for (int i = position; i < positionResult; i++) {
      this->machines_[machine1][i] = this->machines_[machine1][i + 1];
    }
  } else {
    for (int i = position; i > positionResult; i--) {
      this->machines_[machine1][i] = this->machines_[machine1][i - 1];
    }
  }
  this->machines_[machine1][positionResult] = value;
  this->tct(machine1);
}

PmspSolution PmspSolution::getCopy() const {
  PmspSolution solution;
  solution.jobs_ = this->jobs_;
  solution.machines_ = new int*[this->sizeOfMachines_];
  solution.sizeOfMachines_ = this->sizeOfMachines_;
  solution.tasks_ = this->tasks_;
  solution.sizeOfMachineTasks_ = new int[this->sizeOfMachines_];
  solution.tct_values_ = new int[this->sizeOfMachines_];
  for (int i = 0; i < this->sizeOfMachines_; i++) {
    solution.machines_[i] = new int[this->sizeOfMachineTasks_[i]];
    for (int j = 0; j < this->sizeOfMachineTasks_[i]; j++) {
      solution.machines_[i][j] = this->machines_[i][j];
    }
    solution.sizeOfMachineTasks_[i] = this->sizeOfMachineTasks_[i];
    solution.tct_values_[i] = this->tct_values_[i];
  }
  return solution;
}

PmspSolution& PmspSolution::operator=(const PmspSolution& solution) {
  this->jobs_ = solution.jobs_;
  this->machines_ = solution.machines_;
  this->sizeOfMachines_ = solution.sizeOfMachines_;
  this->tasks_ = solution.tasks_;
  this->sizeOfMachineTasks_ = solution.sizeOfMachineTasks_;
  this->tct_values_ = solution.tct_values_;
  return *this;
}

PmspSolution PmspSolution::exchange(int i, int j, int machine1, int machine2) {
  PmspSolution solution = this->getCopy();
  int value = solution.machines_[machine1][i];
  solution.deleteValue(machine1, i);
  solution.insertValue(machine2, value, j);
  return solution;
}

PmspSolution PmspSolution::shaking(int k) {
  PmspSolution solution = this->getCopy(); 
  for (int i = 0; i < k; i++) {
    // Select aleatory machine to select a value
    std::random_device rd2;
    std::mt19937 generator(rd2());
    std::uniform_int_distribution<> dis(0, this->sizeOfMachines_ - 1);
    int machine = dis(generator);

    // Select aleatory value from machine
    std::uniform_int_distribution<> dis2(0, this->sizeOfMachineTasks_[machine] - 1);
    int position = dis2(generator);

    // Select aleatory machine to insert the value
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis3(0, this->sizeOfMachines_ - 1);
    int machine2 = dis3(gen);

    // Select aleatory position to insert the value
    std::uniform_int_distribution<> dis4(0, this->sizeOfMachineTasks_[machine] - 1);
    int position2 = dis4(gen);

    solution.insertValue(machine2, position, position2);
  }
  return solution;
}