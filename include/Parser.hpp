#ifndef __PARSER_HPP__
#define __PARSER_HPP__

#include <string>

#include "PmspProblem.hpp"

class Parser {
  public:
    ~Parser();
    PmspProblem Parse(const std::string& filename);
};

#endif // __PARSER_HPP__
