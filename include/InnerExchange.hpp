#ifndef __INNER_EXCHANGE_HPP__
#define __INNER_EXCHANGE_HPP__

#include "EnvironmentStructures.hpp"

class InnerExchange : public EnvironmentStructures {
  public:
    InnerExchange() = default;
    ~InnerExchange() = default;
    PmspSolution getBestNeighbour(const PmspSolution& solution) override;
    void exchange(PmspSolution& solution, int machine, int position1, int position2);
};

#endif // __INNER_EXCHANGE_HPP__