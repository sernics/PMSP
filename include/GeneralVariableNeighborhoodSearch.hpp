#ifndef __GENERAL_VARIABLE_NEIGHBORHOOD_SEARCH_HPP__
#define __GENERAL_VARIABLE_NEIGHBORHOOD_SEARCH_HPP__

#include "VariableNeighbourDescent.hpp"

class GeneralVariableNeighbourhoodSearch : public VariableNeighbourDescent {
  public:
    GeneralVariableNeighbourhoodSearch() = default;
    PmspSolution execute(PmspProblem& pmspProblem, const int maxIterations = 500);
  private:  
    PmspSolution executeGVNS(PmspProblem& PmspProblem);
};

#endif // __GENERAL_VARIABLE_NEIGHBORHOOD_SEARCH_HPP__