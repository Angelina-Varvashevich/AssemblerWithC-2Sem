#include <iostream>
#include "MyList.h"
#include "MySortedList.h"

int main() {
  MyList<int> list({1, 2, 3, 4, 5, 3, 4, 6});
  std::cout << "list: ";
  list.Print();
  std::cout << "Deleting only one 4: ";
  list.DeleteElement(4, false);
  list.Print();
  std::cout << "Deleting all 3s: ";
  list.DeleteElement(3);
  list.Print();
  std::cout << std::endl;
  MySortedList<int> sorted_list({1, 2, 3, 4, 7, 5});
  std::cout << "Sorted list: ";
  sorted_list.Print();
  return 0;
}
