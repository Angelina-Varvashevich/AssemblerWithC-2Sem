#include <iostream>
#include <vector>
#include "Flowerbed.h"
#include "FileReader.h"
#include "FlowerbedConversion.h"

int main() {
    std::vector<Flowerbed> flowerbeds;
    FileReader::ReadFile("for task 10_02_22.txt", flowerbeds);
    FlowerbedConversion Flowerbeeed(flowerbeds);
    Flowerbeeed.PrintFlowerbedToMap(std::cout);
    std::cout << "Next function" << std::endl;
    Flowerbeeed.FlowerbedWithFlowers(5);
    Flowerbeeed.FlowerbedWithFlowers(4);
    Flowerbeeed.FlowerbedWithFlowers(2);
    std::cout << "Next function" << std::endl;
    Flowerbeeed.ListOfFlowersOnFlowerbed(std::cout, 2);
    Flowerbeeed.ListOfFlowersOnFlowerbed(std::cout, 4);
    std::cout << "Next function" << std::endl;
    Flowerbeeed.MaxFlowersOnFlowerbed(
            std::cout);
    std::cout << "Next function" << std::endl;
    Flowerbeeed.ListOFlowerbedShapes(std::cout);
    std::cout << std::endl;
    std::cout << "Next function" << std::endl;
    std::cout << "Number of flowers on all circle flowerbeds "
              << Flowerbeeed.NumberOfFlowersOnCircleFlowerbed() << std::endl;
    std::cout << "Next function" << std::endl;
    Flowerbeeed.DeleteFlowerFromAllFlowerbeds("rose");
    Flowerbeeed.PrintFlowerbedToMap(std::cout);
    std::string shapes("circle");
    Flowerbeeed.FindFlowerbedWithShape(shapes, std::cout);
    shapes = "square";
    Flowerbeeed.FindFlowerbedWithShape(shapes, std::cout);
    shapes = "ggjhj";
    Flowerbeeed.FindFlowerbedWithShape(shapes, std::cout);


    return 0;

}
