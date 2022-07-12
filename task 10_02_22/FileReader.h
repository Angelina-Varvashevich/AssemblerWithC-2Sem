#ifndef TASK_10_02_22_FILEREADER_H
#define TASK_10_02_22_FILEREADER_H

#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include "Flowerbed.h"

class FileReader {
private:
    static Flowerbed ParseStringToFlowerBed(const std::string &file_string);

public:
    static void ReadFile(const std::string &file_name, std::vector<Flowerbed> &flowerbeds);

};


#endif //TASK_10_02_22_FILEREADER_H
