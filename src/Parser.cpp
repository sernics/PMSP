#include "../include/Parser.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

Parser::~Parser() {}

void Parser::Parse(const std::string& filename) {
  std::ifstream file(filename);
  if (!file.is_open()) {
    std::cerr << "Error: could not open file " << filename << std::endl;
    return;
  }
  std::string line;
  std::getline(file, line);
  std::string word;
  std::stringstream ss(line);
  ss >> word;
  ss >> word;
  int jobs = std::stoi(word);
  std::cout << "Number of machines: " << jobs << std::endl;
  std::getline(file, line);
  std::stringstream ss2(line);
  ss2 >> word;
  ss2 >> word;
  int machines = std::stoi(word);
  std::cout << "Number of jobs: " << machines << std::endl;
  std::getline(file, line);
  std::stringstream ss3(line);
  ss3 >> word;
  int* processing_times = new int[jobs];
  int i = 0;
  while (ss3 >> word) {
    processing_times[i] = std::stoi(word);
    i++;
  }
  std::cout << "Processing times: ";
  for (int i = 0; i < jobs; i++) {
    std::cout << processing_times[i] << " ";
  }
  std::cout << std::endl; 
  int** matrix = new int*[jobs + 1];
  for (int i = 0; i < jobs + 1; i++) {
    matrix[i] = new int[jobs + 1];
  }
  std::getline(file, line);
  for (int i = 0; i < jobs + 1; i++) {
    std::getline(file, line);
    std::stringstream ss(line);
    for (int j = 0; j < jobs + 1; j++) {
      ss >> word;
      matrix[i][j] = std::stoi(word);
    }
  }
  // Print matrix
  for (int i = 0; i < jobs + 1; i++) {
    for (int j = 0; j < jobs + 1; j++) {
      std::cout << matrix[i][j] << " ";
    }
    std::cout << std::endl;
  }
}





