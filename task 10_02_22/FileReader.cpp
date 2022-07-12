#include "FileReader.h"

void FileReader::ReadFile(const std::string &file_name, std::vector<Flowerbed> &flowerbeds) {
    std::ifstream file(file_name);
    if (!file.is_open()) {
        throw std::runtime_error("Files aren't opened. Try again.");
    }
    std::string file_string;
    while (getline(file, file_string)) {
        flowerbeds.push_back(ParseStringToFlowerBed(file_string));
    }
}

Flowerbed FileReader::ParseStringToFlowerBed(const std::string &file_string) {
    if (file_string.empty()) throw std::runtime_error("String is empty. Something wrong.");
    std::string index;
    int index_number;
    int shape;
    std::string word_shape;
    std::string type_of_flower;
    std::vector<std::string> flowers;
    std::stringstream read(file_string);
    read >> index;
    index_number = std::stoi(index);
    read >> word_shape;
    shape = Flowerbed::FlowerbedShapeToShape(shape, word_shape);
    while (read >> type_of_flower) {
        flowers.push_back(type_of_flower);
    }
    return Flowerbed{index_number, shape, flowers};
}