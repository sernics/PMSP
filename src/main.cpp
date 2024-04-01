#include "../include/Parser.hpp"
#include "../include/Pmsp.hpp"
#include "../include/GreedyPmsp.hpp"
#include "../include/GraspPmsp.hpp"

#include <iostream>

int main(int argc, char** argv) {
  std::string filename;
  if (argc == 2) {
    filename = argv[1];
  }
  Parser parser;
  PmspProblem pmspProblem = parser.Parse(filename);
  // pmspProblem.PrintMatrix();
  Pmsp* pmsp = new GreedyPmsp(pmspProblem);
  PmspSolution solution = pmsp->Solve();
  solution.PrintSolution();
  solution.calculateTCT();
  std::cout << "Total time of TCT: " << solution.maxTCT() << std::endl;
  std::cout << std::endl << "Starting with GRASP" << std::endl;
  pmsp = new GraspPmsp(pmspProblem);
  solution = pmsp->Solve();
  solution.PrintSolution();
  solution.calculateTCT();
  std::cout << "Total time of TCT: " << solution.maxTCT() << std::endl;
}
