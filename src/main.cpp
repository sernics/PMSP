#include "../include/Parser.hpp"
#include "../include/PmspProblem.hpp"
#include "../include/PmspSolution.hpp"
#include "../include/Pmsp.hpp"
#include "../include/GreedyPmsp.hpp"
#include "../include/ExecuteGrasp.hpp"
#include "../include/EnvironmentStructures.hpp"

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
  solution.printSolution();
  std::cout << "tct: " << solution.calculateTct() << std::endl;
  ExecuteGrasp executeGrasp(pmspProblem);
  PmspSolution solution2 = executeGrasp.execute();
  solution2.printSolution();
  std::cout << "tct: " << solution2.calculateTct() << std::endl;
  EnvironmentStructures es(solution2);
  es.intraMachinesTaskExchange();
  es.getSolution().printSolution();
  std::cout << "tct 'mejorado': " << es.getSolution().calculateTct() << std::endl;
  return 0;
}
