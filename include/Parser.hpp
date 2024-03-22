#include <string>

#include "Pmsp.hpp"

class Parser {
  public:
    ~Parser();
    Pmsp Parse(const std::string& filename);
};
