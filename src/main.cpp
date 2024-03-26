#include "../include/Parser.hpp"

int main(int argc, char** argv) {
  std::string filename = argv[1];
  Parser parser;
  PmspProblem pmsp = parser.Parse(filename);
  pmsp.PrintMatrix();
}
