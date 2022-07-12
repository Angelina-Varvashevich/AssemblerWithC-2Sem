#include <iostream>
#include<fstream>
#include <list>
#include <string>
#include <algorithm>
#include <vector>
#include <numeric>


int main() {
    ///задание
    std::list<std::string> file_list; //считывание
    std::ifstream file("file for 1 task.txt");
    std::istream_iterator<std::string> file_it(file);
    std::copy(file_it, std::istream_iterator<std::string>(), std::back_inserter(file_list));

    file_list.sort();///сортировка

    std::ostream_iterator<std::string> print(std::cout, " "); ///печать отсортированного списка
    std::copy(file_list.begin(), file_list.end(), print);
    std::cout << std::endl;
    char letter;
    std::cout << "Find words with first letter ";
    std::cin >> letter;
    class FirstLetterEqual {
    private:
        char letter;
    public:
        explicit FirstLetterEqual(char letter_) : letter(letter_) {}

        bool operator()(const std::string &word) const {
            return letter == word[0];
        }
    };

    std::list<std::string>::iterator p1 = find_if(file_list.begin(), file_list.end(), FirstLetterEqual(letter));
    std::list<std::string>::iterator p2 = find_if_not(p1, file_list.end(), FirstLetterEqual(letter));
    std::copy(p1, p2, print);///печать слов на заданную букву
    std::cout << std::endl;
    file_list.erase(p1, p2);///удаление слов на заданную букву
    std::copy(file_list.begin(), file_list.end(), print);///печать после удаления
    std::cout << std::endl;
    file.close();

    ///упражнение
    std::vector<int> file_vector;
    std::ifstream file_numbers("file for task 2.txt ");
    std::istream_iterator<int> it(file_numbers);
    std::copy(it, std::istream_iterator<int>(), std::back_inserter(file_vector));

    int number = 5;
    std::cout << "Count of numbers equal to " << number << " is "
              << std::count(file_vector.begin(), file_vector.end(), number) << std::endl;

    int inf = -10;
    int sup = 10;
    std::cout << "Count of numbers from range is "
              << std::count_if(file_vector.begin(), file_vector.end(), [inf, sup](int num) {
                  return num >= inf && num <= sup;
              }) << std::endl;
    int vector_result = std::accumulate(file_vector.begin(), file_vector.end(), 0);
    if (!file_vector.empty()) {
        std::cout << "Arithmetic mean " << (double) vector_result / file_vector.size() << std::endl;
    } else std::cout << "You can't divide by zero";

    class MyString {
    private:
        std::string string;
    public:
        explicit MyString(std::string string_) : string(std::move(string_)) {}

        bool operator==(const MyString &a) const {
            return string == a.string;
        }

        bool operator<=(const MyString &a) const {
            return string <= a.string;
        }

        bool operator>=(const MyString &a) const {
            return string >= a.string;
        }

        std::string GetString() {
            return string;
        }
    };

    MyString a("like");
    MyString b("animal");
    MyString c("like");
    MyString d("sun");
    MyString e("autumn");
    MyString f("spring");
    MyString g("dream");
    std::vector<MyString> strings{a, b, c, d, e, f, g};
    MyString m("like");
    std::cout << "Count of " << m.GetString() << " is "
              << std::count_if(strings.begin(), strings.end(), [m](const MyString &k) {
                  return m == k;
              }) << std::endl;

    std::cout << "Count of words from range is "
              << std::count_if(strings.begin(), strings.end(), [b, a](const MyString &k) {
                  return k >= b && k <= a;
              });

    return 0;
}
