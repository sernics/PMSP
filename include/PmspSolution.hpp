#ifndef __PMSP_SOLUTION_HPP__
#define __PMSP_SOLUTION_HPP__

#include "PmspProblem.hpp"

class PmspSolution {
  public:
    PmspSolution() = default;
    PmspSolution(PmspProblem problem);
    ~PmspSolution();
    int** getMachines() const { return machines_; }
    int** getTasks() const { return tasks_; }
    void setGreedyTask(bool* inserted);
    int calculateTct();
    void setInitialMachineValues(int* values);
    void printSolution();
    PmspSolution operator=(const PmspSolution& solution);
    void insertValue(int machine, int value, int position);
    void deleteValue(int machine, int position);
  private:
    int jobs_;                      // The number of jobs
    int** machines_;                // The diferent machines with the tasks
    int sizeOfMachines_;            // The number of machines
    int** tasks_;                   // The tasks of the problem (tij)
    int* sizeOfMachineTasks_;       // The number of tasks of each machine
    int* tct_values_;               // The TCT values of each machine
    int machineIndex_;              // The actual machine index

    int tct(int task);
};

#endif // __PMSP_SOLUTION_HPP__
