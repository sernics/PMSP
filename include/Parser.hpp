#include <string>

class Parser {
  public:
    ~Parser();
    void Parse(const std::string& filename);
  private:
    std::string filename_;
};
