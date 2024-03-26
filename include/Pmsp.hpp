#include "PmspProblem.hpp"

class Pmsp {
  public:
    Pmsp() = default;
    Pmsp(PmspProblem problem);
    ~Pmsp();
    PmspProblem getProblem() const { return problem_; }
  private:
    PmspProblem problem_;
};
