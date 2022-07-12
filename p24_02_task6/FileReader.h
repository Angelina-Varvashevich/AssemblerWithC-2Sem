#ifndef P24_02_T6__FILEREADER_H_
#define P24_02_T6__FILEREADER_H_

#include <string>
#include <fstream>
#include <stdexcept>
#include <vector>

class FileReader {
 public:
  static std::string LoadFileIntoString(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open())
      throw std::runtime_error("Can't open the file");
    std::string result;
    std::getline(file, result);
    return result;
  }
  static std::vector<std::string> LoadTextFileIntoVector(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open())
      throw std::runtime_error("Can't open the file");
    std::vector<std::string> result;
    std::string temp;
    while (std::getline(file, temp))
      result.push_back(temp);
    return result;
  }
};

#endif //P24_02_T6__FILEREADER_H_
