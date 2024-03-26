#include "PmspProblem.hpp"

class GreedyPmsp : public Pmsp {
  public:
    GreedyPmsp(PmspProblem pmsp_problem);
    ~GreedyPmsp();
    void Solve() override;
  private:
    PmspProblem pmsp_problem_;
};
