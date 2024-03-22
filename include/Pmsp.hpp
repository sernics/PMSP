class Pmsp {
  public:
    Pmsp() = default;
    Pmsp(int jobs, int machines, int* processing_times, int** matrix);
    ~Pmsp();
    void PrintMatrix();
  private:
    int jobs_;
    int machines_;
    int* processing_times_;
    int** matrix_;
};
