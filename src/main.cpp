#include "../include/Parser.hpp"
#include "../include/PmspProblem.hpp"
#include "../include/PmspSolution.hpp"
#include "../include/Pmsp.hpp"
#include "../include/GreedyPmsp.hpp"

#include <iostream>

int main(int argc, char** argv) {
  std::string filename;
  if (argc == 2) {
    filename = argv[1];
  }
  Parser parser;
  PmspProblem pmspProblem = parser.Parse(filename);
  Pmsp* pmsp = new GreedyPmsp(pmspProblem); 
  PmspSolution solution = pmsp->solve();
  return 0;
}
