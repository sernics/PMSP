#ifndef __OUTER_REINSERTION_HPP__
#define __OUTER_REINSERTION_HPP__

#include "EnvironmentStructures.hpp"

class OuterReinsertion : public EnvironmentStructures {
  public:
    OuterReinsertion() = default;
    ~OuterReinsertion() = default;
    PmspSolution getBestNeighbour(const PmspSolution& solution) override;
    void reinsert(PmspSolution& solution, int i, int j, int machine1, int machine2);
};

#endif // __OUTER_REINSERTION_HPP__