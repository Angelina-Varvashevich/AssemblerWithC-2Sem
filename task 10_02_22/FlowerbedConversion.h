#ifndef TASK_10_02_22_FLOWERBEDCONVERSION_H
#define TASK_10_02_22_FLOWERBEDCONVERSION_H

#include <map>
#include <iostream>
#include <algorithm>
#include <list>
#include <string>
#include <functional>
#include <numeric>
#include "Flowerbed.h"

class FlowerbedConversion {
public:
    explicit FlowerbedConversion(std::vector<Flowerbed> &flowerbeds) {
        for (int i = 0; i < flowerbeds.size(); ++i) {
            flowerbed_multimap.insert(std::make_pair(flowerbeds[i].shape, flowerbeds[i]));
        }
    }

    static void ShapeSorT(std::vector<Flowerbed> &flowerbeds);

    void PrintFlowerbedToMap(std::ostream &out);

    void ListOfFlowersOnFlowerbed(std::ostream &out, int flowerbed_index);

    void ListOFlowerbedShapes(std::ostream &out);

    void MaxFlowersOnFlowerbed(std::ostream &out);

    void FlowerbedWithFlowers(int number_of_flowers);

    int NumberOfFlowersOnCircleFlowerbed();

    void DeleteFlowerFromAllFlowerbeds(const std::string &name_of_flower);

    void FindFlowerbedWithShape(std::string &shape, std::ostream &out);

    [[nodiscard]]const std::multimap<int, Flowerbed> &GetMap() const {
        return flowerbed_multimap;
    }

    static int CalculateCircle(int count_of_flowers, const std::pair<const int, Flowerbed> &flbd);

    friend class Flowerbed;

protected:
    std::multimap<int, Flowerbed> flowerbed_multimap;

    class SumFlowers0nCircleFlowerbeds {
    public:
        int operator()(int count_of_flowers, const std::pair<const int, Flowerbed> &flbd) {
            if (flbd.first == static_cast<int> (Flowerbed::FlowerbedShape::CIRCLE)) {
                return count_of_flowers + flbd.second.flowers.size();
            } else
                return count_of_flowers;
        }
    };
};

#endif //TASK_10_02_22_FLOWERBEDCONVERSION_H
