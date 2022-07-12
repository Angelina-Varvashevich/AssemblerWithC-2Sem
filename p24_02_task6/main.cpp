#include <iostream>
#include "FileReader.h"
#include "ExpressionCalculator.h"

int main() {
  std::vector<std::string> lines = FileReader::LoadTextFileIntoVector("input.txt");
  for (const std::string& line: lines) {
    std::cout << line << " => " << ExpressionCalculator::Calculate(line) << std::endl;
  }
  return 0;
}
