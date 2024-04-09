#include "../include/ExecuteGrasp.hpp"
#include "../include/Pmsp.hpp"
#include "../include/GraspPmsp.hpp"
#include "../include/EnvironmentStructures.hpp"
#include "../include/InnerExchange.hpp"
#include "../include/InnerReinsertion.hpp"
#include "../include/InterExchange.hpp"

#include <iostream>

void printPercentajeImprovement(PmspSolution& solution, PmspSolution& newSolution);

ExecuteGrasp::ExecuteGrasp(PmspProblem problem) : pmspProblem_(problem) {}

PmspSolution ExecuteGrasp::execute() {
  Pmsp* pmsp = new GraspPmsp(pmspProblem_);
  PmspSolution solution = pmsp->solve();
  for (int i = 0; i < 1000; i++) {
    Pmsp* pmsp = new GraspPmsp(pmspProblem_);
    PmspSolution newSolution = pmsp->solve();
    if (newSolution.calculateTct() < solution.calculateTct()) {
      solution = newSolution;
      std::cout << "Tenemos una nueva mejor solucion" << std::endl;
      EnvironmentStructures* environment;
      environment = new InnerExchange(); 
      PmspSolution innerExchangeSolution = environment->getBestNeighbour(solution);
      std::cout << "InnerExchange" << std::endl;
      printPercentajeImprovement(solution, innerExchangeSolution);
      environment = new InnerReinsertion();
      PmspSolution innerReinsertionSolution = environment->getBestNeighbour(solution);
      std::cout << "InnerReinsertion" << std::endl;
      printPercentajeImprovement(solution, innerReinsertionSolution);
      environment = new InterExchange();
      PmspSolution interExchangeSolution = environment->getBestNeighbour(solution);
      std::cout << "InterExchange" << std::endl;
      printPercentajeImprovement(solution, interExchangeSolution);

      // Actualizar solution con la mejor solucion de los vecinos
      if (innerExchangeSolution.calculateTct() < solution.calculateTct()) {
        solution = innerExchangeSolution;
      }
      if (innerReinsertionSolution.calculateTct() < solution.calculateTct()) {
        solution = innerReinsertionSolution;
      }
      if (interExchangeSolution.calculateTct() < solution.calculateTct()) {
        solution = interExchangeSolution;
      }
    }
  }
  return solution;
}

void printPercentajeImprovement(PmspSolution& solution, PmspSolution& newSolution) {
  std::cout << solution.calculateTct() << " -> " << newSolution.calculateTct() << " (" << (solution.calculateTct() - newSolution.calculateTct()) / solution.calculateTct() * 100 << "%)" << std::endl;
}