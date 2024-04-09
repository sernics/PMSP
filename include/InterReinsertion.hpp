#ifndef __INTER_REINSERTION_HPP__
#define __INTER_REINSERTION_HPP__

#include "EnvironmentStructures.hpp"

class InterReinsertion : public EnvironmentStructures {
  public:
    InterReinsertion() = default;
    ~InterReinsertion() = default;
    PmspSolution getBestNeighbour(const PmspSolution& solution) override;
    void reinsert(PmspSolution& solution, int i, int j, int machine1, int machine2);
};

#endif // __INNER_REINSERTION_HPP__