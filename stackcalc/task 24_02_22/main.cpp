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
    for (auto i: sort) {
      std::cout << i;
    }
    sort.Print(std::cout);
    std::cout<<std::endl;

    std::cout << MyList.LastElement();
    std::cout << "Stack on List" << std::endl;
    StackOnList<int> stack;
    std::cout << "Is empty" << stack.Empty() << std::endl;
    stack.Push(1);
    stack.Push(2);
    stack.Push(3);
    stack.Push(4);
    stack.Push(5);
    std::cout << "Is empty" << stack.Empty() << std::endl;
    stack.Print(std::cout);
    std::cout << std::endl;
    std::cout << "On top " << stack.Top() << std::endl;
    stack.Pop();
    stack.Print(std::cout);
    std::cout << std::endl;
    stack.Pop();
    stack.Pop();
    stack.Print(std::cout);
    std::cout << std::endl;
    std::cout << "On top " << stack.Top() << std::endl;


    std::cout << "Task 6";
    std::cout << std::endl;
    std::vector<std::string> expressions;
    FileReader::ReadFile("for task 6.txt", expressions);
    for (const std::string &expr: expressions) {
        std::cout << Calculate::PublicResult(expr) << " ";
    }








}
