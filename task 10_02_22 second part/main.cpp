#include <iostream>
#include <list>
#include <string>
#include <vector>
#include "Tasks.h"

int main() {
    std::list<std::string> file_list;
    FistFromFile(file_list, "file for task.txt");/// work 1
    PrintList(file_list);/// work 2
    std::cout << "Next task" << std::endl;
    std::list<std::string> file_list_another;
    CopyFromOneToAnother(file_list, file_list_another);///work3
    PrintList(file_list_another);
    std::cout << "Next task" << std::endl;///work4
    Person scd_person("Ilia", 25, 180, 80);
    Person thrd_person("Cape", 17, 176, 80);
    Person fst_person("Andrew", 25, 180, 90);
    std::vector<Person> persons;
    persons.push_back(fst_person);
    persons.push_back(scd_person);
    persons.push_back(thrd_person);
    CustomSortingName(persons);
    PrintVector(persons, std::cout);
    std::cout << "Next task" << std::endl;///work4
    CustomSortingPerson(persons);
    PrintVector(persons, std::cout);
    std::cout << "Next task" << std::endl;
    PrintList(FindWordsWithFirstLetterLambda(file_list_another, 'c'));///work5
    std::cout << "Next task" << std::endl;
    PrintList(FindWordsWithFirstLetterFunctor(file_list_another, 'c'));
    std::cout << "Next task" << std::endl;
    DeleteWordsWithFirstLetter(file_list_another, 'c');///work6
    PrintList(file_list_another);
    std::cout << "Next task" << std::endl;//7 has some problems
    char ch = 'c';
    std::cout << "Count of words with " << ch << " is " << CountOfWordsWithLetter(file_list_another, ch) << std::endl;
    std::cout << "Next task" << std::endl;
    PrintReverseInformation(file_list_another);///work 8
    std::cout << "Next task" << std::endl;
    std::map<std::string, int> file_list_map;///work9
    PrintUniqueWords(file_list, file_list_map, std::cout);
    std::cout << std::endl;
    std::cout << "Next task" << std::endl;
    std::multimap<std::string, int> file_list_multimap;
    NumberOfWordRepetition(file_list, file_list_multimap, file_list_map, std::cout);///work10

    std::cout << "Next task" << std::endl; //for11
    Person fifth("Luise", 18, 160, 50);
    Person sixth("Ann", 25, 160, 48);
    persons.push_back(fifth);
    persons.push_back(sixth);
    SortOneKey(persons, std::less_equal<int>());//11 has some problems
    PrintVector(persons, std::cout);
    std::cout << "Next task" << std::endl;
    SortTwoKeys(persons, std::less_equal<int>());
    PrintVector(persons, std::cout);
    std::cout << std::endl;
    std::cout << "Next task" << std::endl;
    SortThreeKeys(persons, std::less_equal<int>());
    PrintVector(persons, std::cout);


    return 0;
}
