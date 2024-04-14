#include "../include/Parser.hpp"
#include "../include/PmspProblem.hpp"
#include "../include/PmspSolution.hpp"
#include "../include/Pmsp.hpp"
#include "../include/GreedyPmsp.hpp"
// #include "../include/ExecuteGrasp.hpp"
#include "../include/GeneralVariableNeighborhoodSearch.hpp"

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
  std::cout << "Greedy solution" << std::endl;
  solution.printSolution();
  std::cout << "tct: " << solution.calculateTct() << std::endl << std::endl;

  GeneralVariableNeighbourhoodSearch gvns;
  PmspSolution gvnsSolution = gvns.execute(pmspProblem);
  std::cout << "GVNS solution" << std::endl;
  gvnsSolution.printSolution();
  std::cout << "tct: " << gvnsSolution.calculateTct() << std::endl << std::endl;
  return 0;
}
