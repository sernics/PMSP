#ifndef __PMSP_SOLUTION_HPP__
#define __PMSP_SOLUTION_HPP__

#include "PmspProblem.hpp"

#include <queue>

class PmspSolution {
  public:
    PmspSolution(PmspProblem problem);
    ~PmspSolution();
    int** getMachines() const { return machines_; }
    int** getTasks() const { return tasks_; }
    void setGreedyTask(std::queue<int>& positions, bool* inserted);
    int calculateTct();
    void setInitialMachineValues(int* values);
    void printSolution();
  private:
    int** machines_;                // The diferent machines with the tasks
    int sizeOfMachines_;            // The number of machines
    int** tasks_;                   // The tasks of the problem (tij)
    int* sizeOfMachineTasks_;       // The number of tasks of each machine

    int tct(int task);
};

#endif // __PMSP_SOLUTION_HPP__
