#ifndef TASK_10_02_22_SECOND_PART_TASKS_H
#define TASK_10_02_22_SECOND_PART_TASKS_H

#include <list>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <iterator>
#include<functional>

void FistFromFile(std::list<std::string> &file_list, const std::string &file_name);

void PrintList(const std::list<std::string> &file_list);

void CopyFromOneToAnother(const std::list<std::string> &file_list, std::list<std::string> &file_list_anoter);

class Person {
public:
    std::string name;
    int year;
    int high;
    int weight;

    Person(std::string name_, int year_, int high_, int weight_) : name(std::move(name_)), year(year_), high(high_), weight(weight_) {}

    bool operator<(const Person &second) const {
        return this->year < second.year;
    }
};

void CustomSortingName(std::vector<Person> &persons);

void PrintVector(const std::vector<Person> &persons, std::ostream &out);

void CustomSortingPerson(std::vector<Person> &persons);

class FirstLetterEqual {
private:
    char letter;
public:
    explicit FirstLetterEqual(char letter_) : letter(letter_) {}

    bool operator()(const std::string &word) const {
        return letter == word[0];////////////////
    }
};

std::list<std::string> FindWordsWithFirstLetterLambda(const std::list<std::string> &file_list, char letter);

std::list<std::string> FindWordsWithFirstLetterFunctor(const std::list<std::string> &file_list, char letter);

void DeleteWordsWithFirstLetter(std::list<std::string> &file_list, char letter);

int CountOfWordsWithLetter(const std::list<std::string> &file_list, char letter);

void PrintReverseInformation(const std::list<std::string> &file_list);

void
PrintUniqueWords(const std::list<std::string> &file_list, std::map<std::string, int> &file_list_map, std::ostream &out);

void SortOneKey(std::vector<Person> &persons, const std::function<bool(int , int)> &Pred);

void SortTwoKeys(std::vector<Person> &persons, const std::function<bool(int, int)> &Pred);

void SortThreeKeys(std::vector<Person> &persons, const std::function<bool(int, int)> &Pred);
void NumberOfWordRepetition(const std::list<std::string> &file_list, std::multimap<std::string, int> &file_list_multimap ,std::map<std::string, int> &file_list_map,
                            std::ostream &out);

#endif //TASK_10_02_22_SECOND_PART_TASKS_H