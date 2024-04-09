#include "../include/Parser.hpp"
#include "../include/PmspProblem.hpp"
#include "../include/PmspSolution.hpp"
#include "../include/Pmsp.hpp"
#include "../include/GreedyPmsp.hpp"
#include "../include/ExecuteGrasp.hpp"
#include "../include/EnvironmentStructures.hpp"
#include "../include/InterExchange.hpp"

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

  ExecuteGrasp executeGrasp(pmspProblem);
  PmspSolution graspSolution = executeGrasp.execute();
  std::cout << "Grasp solution" << std::endl;
  graspSolution.printSolution();
  std::cout << "tct: " << graspSolution.calculateTct() << std::endl << std::endl;

  // EnvironmentStructures* innerExchange = new InnerExchange();
  // PmspSolution bestNeighbour = innerExchange->getBestNeighbour(graspSolution);
  // std::cout << bestNeighbour.calculateTct() << std::endl;

  EnvironmentStructures* interExchange = new InterExchange();
  PmspSolution bestNeighbour = interExchange->getBestNeighbour(graspSolution);
  bestNeighbour.printSolution();
  std::cout << bestNeighbour.calculateTct() << std::endl;
  return 0;
}
