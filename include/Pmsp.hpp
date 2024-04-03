#ifndef __PMSP_HPP__
#define __PMSP_HPP__

#include "PmspSolution.hpp"

class Pmsp {
  public:
    virtual PmspSolution solve() = 0;
};

#endif // __PMSP_HPP__
