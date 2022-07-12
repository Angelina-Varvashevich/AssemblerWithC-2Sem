#ifndef TASK_24_02_22_FILEREADER_H
#define TASK_24_02_22_FILEREADER_H
#include <string>
#include <fstream>
class FileReader{
public:
    static void ReadFile(const std::string &file_name, std::vector<std::string> &expressions) {
        std::ifstream file(file_name);
        if (!file.is_open()) {
            throw std::runtime_error("File isn't opened. Try again.");
        }
        std::string file_string;
        while (getline(file, file_string)) {
            expressions.push_back(file_string);
        }
    }
};

#endif //TASK_24_02_22_FILEREADER_H
