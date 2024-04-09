#ifndef __ENVIRONMENT_STRUCTURES_HPP__
#define __ENVIRONMENT_STRUCTURES_HPP__

#include "PmspSolution.hpp"

class EnvironmentStructures {
  public:
    virtual PmspSolution getBestNeighbour(const PmspSolution& solution) = 0;
};

#endif // __ENVIRONMENT_STRUCTURES_HPP__