#ifndef __PMSP_SOLUTION_HPP__
#define __PMSP_SOLUTION_HPP__

#include "PmspProblem.hpp"
#include <vector>

class PmspSolution {
  public:
    PmspSolution(PmspProblem& pmsp_problem);
    ~PmspSolution();
    void pushInitialSolution(std::vector<int>& solution); 
    void pushIndex(int i, int value);
    // Overload the [] operator to access the solution
    std::vector<int>& operator[](int i) {
      return solution_[i];
    }
    int getLastElement(int i);
    void PrintSolution();
    int calculateTCT();
  private:
    std::vector<std::vector<int>> solution_;
    PmspProblem pmsp_problem_;
};

#endif // __PMSP_SOLUTION_HPP__
