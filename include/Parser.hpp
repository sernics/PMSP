#include <string>

#include "PmspProblem.hpp"

class Parser {
  public:
    ~Parser();
    PmspProblem Parse(const std::string& filename);
};
