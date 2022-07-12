#ifndef TASK_10_02_22_FLOWERBED_H
#define TASK_10_02_22_FLOWERBED_H

#include <algorithm>
#include <string>
#include <vector>
#include <utility>

class Flowerbed {
public:
    Flowerbed() = default;

    int index_number = 0;
    int shape = 0;
    std::vector<std::string> flowers;
    enum FlowerbedShape {
        CIRCLE,//0
        SQUARE,//1
        RHOMB,//2
        OTHER//3
    };

    Flowerbed(int index_number_, int shape_, std::vector<std::string> flowers_) :
            index_number(index_number_), shape(shape_), flowers(std::move(flowers_)) {}

    static std::string FlowerbedShapeToString(FlowerbedShape shape);

    static int FlowerbedStringToInt(std::string &shape);

    static std::string ShapeIntTostring(int shape);

    static int FlowerbedShapeToShape(int &shape, std::string &word);

};


#endif //TASK_10_02_22_FLOWERBED_H
