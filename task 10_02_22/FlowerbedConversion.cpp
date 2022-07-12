#include "FlowerbedConversion.h"

void FlowerbedConversion::ShapeSorT(std::vector<Flowerbed> &flowerbeds) {
    std::sort(flowerbeds.begin(), flowerbeds.end(), [](const Flowerbed &a, const Flowerbed &b) {
        return a.shape < b.shape;
    });
}

void FlowerbedConversion::PrintFlowerbedToMap(std::ostream &out) {
    for (std::pair<int, Flowerbed> it: flowerbed_multimap) {
        out <<Flowerbed::ShapeIntTostring( it.first )<< "\t" << it.second.index_number << " " << Flowerbed::ShapeIntTostring(it.second.shape)
            << " ";
        for (const std::string &flower: it.second.flowers) {
            out << flower << " ";
        }
        out << std::endl;
    }
}




void FlowerbedConversion::ListOfFlowersOnFlowerbed(
        std::ostream &out, int flowerbed_index) {
    std::list<std::string> FlowersList;
    int flowerbeds_count = 0;
    for (std::pair<int, Flowerbed> it: flowerbed_multimap) {
        ++flowerbeds_count;
        if (it.second.index_number == flowerbed_index) {
            Flowerbed CurrentFLB = it.second;
            for (const std::string &flower: CurrentFLB.flowers) {
                FlowersList.push_back(flower);
            }
        }
    }
    if (flowerbed_index < flowerbeds_count) {
        std::ostream_iterator<std::string> outs(out, ",");
        out << "There are ";
        std::copy(FlowersList.begin(), FlowersList.end(), outs);
        out << "on flowerbed number " << flowerbed_index << std::endl;
    } else out << "Flowerbed doesn't exist" << std::endl;
}

void FlowerbedConversion::ListOFlowerbedShapes(std::ostream &out) {
    std::list<std::string> ShapeList;
    std::list<std::string>::iterator iter;
    for (std::pair<int, Flowerbed> it: flowerbed_multimap) {
        if (static_cast <Flowerbed::FlowerbedShape> (it.first) == Flowerbed::CIRCLE) {
            std::list<std::string>::iterator begin = ShapeList.begin();
            std::list<std::string>::iterator end = ShapeList.end();
            auto found{std::find(begin, end, "circle")};
            if (found == end) ShapeList.push_back("circle");
        }
        if (static_cast <Flowerbed::FlowerbedShape> (it.first) == Flowerbed::SQUARE) {
            std::list<std::string>::iterator begin = ShapeList.begin();
            std::list<std::string>::iterator end = ShapeList.end();
            auto found{std::find(begin, end, "square")};
            if (found == end) ShapeList.push_back("square");
        }
        if (static_cast <Flowerbed::FlowerbedShape> (it.first) == Flowerbed::RHOMB) {
            std::list<std::string>::iterator begin = ShapeList.begin();
            std::list<std::string>::iterator end = ShapeList.end();
            auto found{std::find(begin, end, "rhomb")};
            if (found == end) ShapeList.push_back("rhomb");
        }
    }
    out << "All flowerbed's shapes: ";
    for (iter = ShapeList.begin();
         iter != ShapeList.end(); ++iter) {
        out << *iter << " ";
    }
}

void FlowerbedConversion::MaxFlowersOnFlowerbed(std::ostream &out) {
    std::list<std::string> FlowersList;
    int current_max_size = 0;
    int index = -1;

    for (std::pair<int, Flowerbed> it: flowerbed_multimap) {
        if (it.second.flowers.size() > current_max_size) {
            current_max_size = it.second.flowers.size();
            index = it.second.index_number;
        }
    }
    out << "Flowerbed number " << index << " has a lot of flowers" << std::endl;
}

void FlowerbedConversion::FlowerbedWithFlowers(int number_of_flowers) {
    std::for_each(flowerbed_multimap.begin(), flowerbed_multimap.end(),
                  [number_of_flowers](const std::pair<int, Flowerbed> &flb_pair) {
                      Flowerbed flb = flb_pair.second;
                      if (flb.flowers.size() == number_of_flowers) {
                          std::cout << "Flowerbed number " << flb.index_number << " has " << number_of_flowers
                                    << " flowers"
                                    << std::endl;
                      }
                  });
}

int FlowerbedConversion::CalculateCircle(int count_of_flowers, const std::pair<const int, Flowerbed> &flbd) {
    if (flbd.first == static_cast<int> (Flowerbed::FlowerbedShape::CIRCLE)) {
        return count_of_flowers + flbd.second.flowers.size();
    } else
        return count_of_flowers;
}

int FlowerbedConversion::NumberOfFlowersOnCircleFlowerbed() {
    int result_lambda = std::accumulate(flowerbed_multimap.begin(), flowerbed_multimap.end(), 0,
                                        [](int count_of_flowers, const std::pair<const int, Flowerbed> &flbd) -> int {
                                            if (flbd.first == static_cast<int> (Flowerbed::FlowerbedShape::CIRCLE)) {
                                                return count_of_flowers + flbd.second.flowers.size();
                                            } else
                                                return count_of_flowers;
                                        });
    int result_function = std::accumulate(flowerbed_multimap.begin(), flowerbed_multimap.end(), 0, CalculateCircle);

    FlowerbedConversion::SumFlowers0nCircleFlowerbeds sum;
    int result_funct = std::accumulate(flowerbed_multimap.begin(), flowerbed_multimap.end(), 0, sum);

    if (result_funct == result_lambda && result_function == result_lambda) return result_lambda;
    else return -1;
}

void FlowerbedConversion::DeleteFlowerFromAllFlowerbeds(const std::string &name_of_flower) {
    for (std::pair<int, Flowerbed> it: flowerbed_multimap) {
        Flowerbed &CurrentFLB = it.second;
        auto result = std::remove_if(CurrentFLB.flowers.begin(), CurrentFLB.flowers.end(),
                                     [name_of_flower](const std::string &flower) {
                                         return flower == name_of_flower;
                                     });
        CurrentFLB.flowers.erase(result, CurrentFLB.flowers.end());
    }
}

void FlowerbedConversion::FindFlowerbedWithShape(std::string &shape, std::ostream &out) {
    std::vector<int> flowerbed_index;
    std::for_each(flowerbed_multimap.begin(), flowerbed_multimap.end(),
                  [&shape, &flowerbed_index](const std::pair<int, Flowerbed> &flb_pair) {
                      int current_shape = flb_pair.first;
                      if (current_shape == Flowerbed::FlowerbedStringToInt(shape)) {
                          flowerbed_index.push_back(flb_pair.second.index_number);
                      }
                  });
    if (!flowerbed_index.empty()) {
        out << shape << " flowerbed number: ";
        for (int num: flowerbed_index) {
            out << num << " ";
        }
        out << std::endl;
    } else out << "There aren't flowerbeds of" << shape << std::endl;
}















