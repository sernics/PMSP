#ifndef __INTER_EXCHANGE_HPP__
#define __INTER_EXCHANGE_HPP__

#include "EnvironmentStructures.hpp"

class InterExchange : public EnvironmentStructures {
  public:
    InterExchange() = default;
    ~InterExchange() = default;
    PmspSolution getBestNeighbour(const PmspSolution& solution) override;
    void exchange(PmspSolution& solution, int i, int j, int machine1, int machine2);
};

#endif // __INNER_EXCHANGE_HPP__