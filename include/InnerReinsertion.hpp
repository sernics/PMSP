#ifndef __INNER_REINSERTION_HPP__
#define __INNER_REINSERTION_HPP__

#include "EnvironmentStructures.hpp"

class InnerReinsertion : public EnvironmentStructures {
  public:
    InnerReinsertion() = default;
    ~InnerReinsertion() = default;
    PmspSolution getBestNeighbour(const PmspSolution& solution) override;
    void reinsert(PmspSolution& solution, int i, int j, int machine);
};

#endif // __INNER_REINSERTION_HPP__