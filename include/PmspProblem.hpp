#ifndef PMSP_PROBLEM_HPP
#define PMSP_PROBLEM_HPP

class PmspProblem {
  public:
    PmspProblem() = default;
    PmspProblem(int jobs, int machines, int* processing_times, int** matrix);
    ~PmspProblem();
    int getJobs() const { return jobs_; }
    int getMachines() const { return machines_; }
    int* getProcessingTimes() const { return processing_times_; }
    int** getSetup() const { return matrix_; }
    int** getTasks() const { return tasks_; }
    void PrintMatrix();
  private:
    int jobs_;
    int machines_;
    int* processing_times_;
    int** matrix_;
    int** tasks_;
};

#endif // PMSP_PROBLEM_HPP
