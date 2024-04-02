#include "../include/Parser.hpp"
#include "../include/Pmsp.hpp"
#include "../include/GreedyPmsp.hpp"
#include "../include/ExecuteGrasp.hpp"

#include <iostream>

int main(int argc, char** argv) {
  std::string filename;
  if (argc == 2) {
    filename = argv[1];
  }
  Parser parser;
  PmspProblem pmspProblem = parser.Parse(filename);
  // pmspProblem.PrintMatrix();
  std::cout << "Starting with GREEDY" << std::endl << std::endl;
  Pmsp* pmsp = new GreedyPmsp(pmspProblem);
  PmspSolution solution = pmsp->Solve();
  solution.PrintSolution();
  std::cout << "Total time of TCT: " << solution.calculateTCT() << std::endl << std::endl;
  std::cout << std::endl << "Starting with GRASP" << std::endl;
  ExecuteGrasp* executeGrasp = new ExecuteGrasp(pmspProblem);
  PmspSolution graspSolution = executeGrasp->Execute();
  graspSolution.PrintSolution();
  std::cout << "Total time of TCT: " << graspSolution.calculateTCT() << std::endl;
}
