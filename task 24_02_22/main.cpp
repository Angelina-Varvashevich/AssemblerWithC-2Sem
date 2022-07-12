#include <iostream>
#include <functional>
#include "List.h"
#include "SortedList.h"
#include "StackOnList.h"
#include "FileReader.h"
#include"task6.h"

int main() {

    List<int> MyList;
    MyList.PushBack(4);
    MyList.PushBack(5);
    MyList.PushBack(7);
    MyList.PushBack(10);
    MyList.PushBack(11);
    MyList.Print(std::cout);
    std::cout << std::endl;
    MyList.RemoveAt(5);
    MyList.Print(std::cout);
    std::cout << std::endl;
    MyList.RemoveAt(11);
    MyList.Print(std::cout);
    std::cout << std::endl;
    MyList.RemoveAt(0);
    MyList.Print(std::cout);
    std::cout << std::endl;
    MyList.RemoveAt(13);
    MyList.Print(std::cout);
    MyList.PushFront(12);
    std::cout << std::endl;
    MyList.Print(std::cout);
    std::cout << std::endl;

    std::cout << "Sorted List" << std::endl;
    SortedList<int> sort;
    sort.Insert(10);
    sort.Insert(2);
    sort.Insert(7);
    sort.Insert(8);
    sort.Print(std::cout);
    std::cout << std::endl;
    std::cout << "Sorted List2" << std::endl;
    sort.Insert(5);
    sort.Insert(3);
    sort.Insert(2);
    sort.Insert(1);
    sort.Print(std::cout);
    std::cout<<std::endl;

    std::cout << "Task 6";
    std::cout << std::endl;
    std::vector<std::string> expressions;
    FileReader::ReadFile("for task 6.txt", expressions);
    for (const std::string &expr: expressions) {
        std::cout << Calculate::PublicResult(expr) << " ";
    }
}
