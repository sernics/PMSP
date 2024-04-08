#ifndef __PMSP_SOLUTION_HPP__
#define __PMSP_SOLUTION_HPP__

#include "PmspProblem.hpp"

class PmspSolution {
  public:
    // Constructors and destructors
    PmspSolution() = default;
    PmspSolution(PmspProblem problem);
    ~PmspSolution();
    // Setters
    void setGreedyTask(bool* inserted);
    void setGraspTask(bool* inserted);
    // Getters
    int** getMachines() const { return machines_; }
    int** getTasks() const { return tasks_; }
    int getSizeOfMachine(int machine) const { return sizeOfMachineTasks_[machine]; }
    int getMachineSize() const { return sizeOfMachines_; }
    // Methods
    int calculateTct();
    int tct(int machine);
    void setInitialMachineValues(int* values);
    void printSolution();
    void insertValue(int machine, int value, int position);
    void deleteValue(int machine, int position);
    void swapValues(int machine1, int position1, int machine2, int position2);
  private:
    // Attributes
    int jobs_;                      // The number of jobs
    int** machines_;                // The diferent machines with the tasks
    int sizeOfMachines_;            // The number of machines
    int** tasks_;                   // The tasks of the problem (tij)
    int* sizeOfMachineTasks_;       // The number of tasks of each machine
    int* tct_values_;               // The TCT values of each machine
};

#endif // __PMSP_SOLUTION_HPP__
