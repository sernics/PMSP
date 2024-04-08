#ifndef __ENVIRONMENT_STRUCTURES_HPP__
#define __ENVIRONMENT_STRUCTURES_HPP__

#include "PmspSolution.hpp"

class EnvironmentStructures {
  public:
    EnvironmentStructures() = default;
    EnvironmentStructures(PmspSolution solution);
    PmspSolution getSolution() const { return solution_; }
    void intraMachinesTaskExchange();
    void interMachinesTaskExchange();
    void reinsertionInterMachines();
    void reinsertionIntraMachines();
  private:
    PmspSolution solution_;
};

#endif // __ENVIRONMENT_STRUCTURES_HPP__