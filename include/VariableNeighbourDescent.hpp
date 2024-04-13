#ifndef __VARIABLENEIGHBOURDESCENT_HPP__
#define __VARIABLENEIGHBOURDESCENT_HPP__

#include "EnvironmentStructures.hpp"
#include "InnerExchange.hpp"
#include "InterExchange.hpp"
#include "InnerReinsertion.hpp"
#include "InterReinsertion.hpp"

class VariableNeighbourDescent {
  public:
    VariableNeighbourDescent();
    PmspSolution execute(PmspSolution& initialSolution);
};


#endif // __VARIABLENEIGHBOURDESCENT_HPP__