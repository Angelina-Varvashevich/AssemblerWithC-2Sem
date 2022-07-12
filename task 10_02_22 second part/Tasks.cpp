#include "Tasks.h"

void FistFromFile(std::list<std::string> &file_list, const std::string &file_name) {
    std::ifstream file(file_name);
    std::istream_iterator<std::string> file_it(file);
    std::copy(file_it, std::istream_iterator<std::string>(), std::back_inserter(file_list));
    file.close();
}

void PrintList(const std::list<std::string> &file_list) {
    std::ostream_iterator<std::string> print(std::cout, " ");
    std::copy(file_list.begin(), file_list.end(), print);
    std::cout << std::endl;
}

void CopyFromOneToAnother(const std::list<std::string> &file_list,
                          std::list<std::string> &file_list_anoter) {
    std::copy(file_list.begin(), file_list.end(), std::inserter(file_list_anoter, file_list_anoter.begin()));
}

void CustomSortingName(
        std::vector<Person> &persons) {
    std::sort(persons.begin(), persons.end(), [](const Person &first, const Person &second) {
        return first.name < second.name;
    });
}

void PrintVector(const std::vector<Person> &persons, std::ostream &out) {
    for (const Person &ppl: persons) {
        out << ppl.name << " " << ppl.high << " " << ppl.year << " " << ppl.weight << std::endl;
    }
}

void CustomSortingPerson(std::vector<Person> &persons) {
    std::sort(persons.begin(), persons.end());
}

std::list<std::string> FindWordsWithFirstLetterLambda(const std::list<std::string> &file_list,
                                                      char letter) {
    std::list<std::string> current_list;
    std::copy_if(file_list.begin(), file_list.end(), std::back_inserter(current_list),
                 [letter](const std::string &word) -> bool {
                     return letter == word[0];
                 });
    return current_list;
}


std::list<std::string> FindWordsWithFirstLetterFunctor(const std::list<std::string> &file_list,
                                                       char letter) {
    std::list<std::string> current_list;
    FirstLetterEqual equal(letter);
    std::copy_if(file_list.begin(), file_list.end(), std::back_inserter(current_list), equal);
    return current_list;
}

void DeleteWordsWithFirstLetter(std::list<std::string> &file_list, char letter) {
    auto result = std::remove_if(file_list.begin(), file_list.end(),
                                 [letter](const std::string &word) {
                                     return letter == word[0];
                                 });
    file_list.erase(result, file_list.end());
}

int CountOfWordsWithLetter(const std::list<std::string> &file_list,
                           char letter) {
    return std::count_if(file_list.begin(), file_list.end(), [letter](const std::string &word) {
        std::string::const_iterator begin;
        std::string::const_iterator end;
        auto found{std::find(begin, end, letter)};
        return found != end;
    });
}

void PrintReverseInformation(const std::list<std::string> &file_list) {
    std::copy(file_list.rbegin(), file_list.rend(), std::ostream_iterator<std::string>(std::cout, " "));
    std::cout << std::endl;
}

void PrintUniqueWords(const std::list<std::string> &file_list, std::map<std::string, int> &file_list_map,
                      std::ostream &out) {
    int count = 0;
    for (const std::string &word: file_list) {
        file_list_map.insert(std::make_pair(word, ++count));
    }
    out << "Count of unique words: " << file_list_map.size() << std::endl;
    for (std::pair<std::string, int> pair: file_list_map) {
        out << pair.first << " ";
    }
}

void
NumberOfWordRepetition(const std::list<std::string> &file_list, std::multimap<std::string, int> &file_list_multimap,
                       std::map<std::string, int> &file_list_map,
                       std::ostream &out) {
    int count = 0;
    for (const std::string &word: file_list) {
        file_list_multimap.insert(std::make_pair(word, ++count));
    }
    for (std::pair<std::string, int> pair_map: file_list_map) {
        int result = std::count_if(file_list_multimap.begin(), file_list_multimap.end(),
                                   [pair_map](const std::pair<std::string, int> &pair) {
                                       return pair.first == pair_map.first;
                                   });
        out << pair_map.first << " repeats " << result << " times" << std::endl;
    }
}

void SortOneKey(std::vector<Person> &persons, const std::function<bool(int, int)> &Pred) {
    std::sort(persons.begin(), persons.end(), [&Pred](const Person &first, const Person &second) {
        return Pred(first.high, second.high);
    });
}

void SortTwoKeys(std::vector<Person> &persons, const std::function<bool(int, int)> &Pred) {
    std::sort(persons.begin(), persons.end(), [&Pred](const Person &first, const Person &second) {
        if (first.high == second.high) return Pred(first.year, second.year);
        else return Pred(first.high, second.high);
    });
}

void SortThreeKeys(std::vector<Person> &persons, const std::function<bool(int, int)> &Pred) {
    std::sort(persons.begin(), persons.end(), [&Pred](const Person &first, const Person &second) {
        if (first.high == second.high && first.year == second.year) return Pred(first.weight, second.weight);
        else if (first.high == second.high) return Pred(first.year, second.year);
        else return Pred(first.high, second.high);
    });
}
