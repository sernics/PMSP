#ifndef __OUTER_EXCHANGE_HPP__
#define __OUTER_EXCHANGE_HPP__

#include "EnvironmentStructures.hpp"

class OuterExchange : public EnvironmentStructures {
  public:
    OuterExchange() = default;
    ~OuterExchange() = default;
    PmspSolution getBestNeighbour(const PmspSolution& solution) override;
    void exchange(PmspSolution& solution, int i, int j, int machine1, int machine2);
};

#endif // __OUTER_EXCHANGE_HPP__