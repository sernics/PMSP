#include "../include/Parser.h"
#include <fstream>
#include <iostream>

Parser::Parser(const std::string& filename) : filename_(filename) {}

Parser::~Parser() {}

void Parser::Parse() {
  std::ifstream file(filename_);
  if (!file.is_open()) {
    std::cerr << "Error: could not open file " << filename_ << std::endl;
    return;
  }
  std::string line;
  while (std::getline(file, line)) {
    std::cout << line << std::endl;
  }
}
