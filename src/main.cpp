#include "../include/Parser.hpp"
#include "../include/Pmsp.hpp"
#include "../include/GreedyPmsp.hpp"

int main(int argc, char** argv) {
  std::string filename = argv[1];
  Parser parser;
  PmspProblem pmspProblem = parser.Parse(filename);
  pmspProblem.PrintMatrix();
  Pmsp* pmsp = new GreedyPmsp(pmspProblem);
  pmsp->Solve();
}
