#include "../include/Parser.h"

int main(int argc, char** argv) {
  std::string filename = argv[1];
  Parser parser(filename);
  parser.Parse();
}
