#include "Flowerbed.h"

int Flowerbed::FlowerbedShapeToShape(int &shape, std::string &word) {
    if (word == "circle") {
        return shape = static_cast<int>(CIRCLE);
    } else if (word == "square") {
        return shape = static_cast<int>(SQUARE);
    } else if (word == "rhomb") {
        return shape = static_cast<int>(RHOMB);
    } else return shape = static_cast<int>(OTHER);
}

std::string Flowerbed::FlowerbedShapeToString(FlowerbedShape shape) {
    switch (shape) {
        case CIRCLE:
            return "circle";
        case SQUARE:
            return "square";
        case RHOMB:
            return "rhomb";
        default:
            return "other type";
    }
}

int Flowerbed::FlowerbedStringToInt(std::string &shape) {
    if (shape == "circle") return static_cast<int>(CIRCLE);
    if (shape == "square") return static_cast<int>(SQUARE);
    if (shape == "rhomb") return static_cast<int>(RHOMB);
    else return OTHER;
}

std::string Flowerbed::ShapeIntTostring(int shape) {
    if (shape == static_cast<int>(CIRCLE)) return "circle";
    if (shape == static_cast<int>(SQUARE)) return "square";
    if (shape == static_cast<int>(RHOMB)) return "rhomb";
    else return "other shape";
}












