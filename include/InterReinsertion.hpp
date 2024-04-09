#ifndef __INTER_REINSERTION_HPP__
#define __INTER_REINSERTION_HPP__

#include "EnvironmentStructures.hpp"

class InterExchange : public EnvironmentStructures {
  public:
    InterExchange() = default;
    ~InterExchange() = default;
    PmspSolution getBestNeighbour(const PmspSolution& solution) override;
    void reinsert(PmspSolution& solution, int i, int j, int machine1, int machine2);
};

#endif // __INNER_REINSERTION_HPP__