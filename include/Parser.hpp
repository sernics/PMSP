#include <fstream>

class Parser {
  public:
    Parser(const std::string& filename);
    ~Parser();
    void Parse();
  private:
    std::string filename_;
};
