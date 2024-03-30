#ifndef __PMSP_HPP__
#define __PMSP_HPP__

#include "PmspSolution.hpp"

class Pmsp {
  public:
    virtual PmspSolution Solve() = 0;
};

#endif // __PMSP_HPP__
