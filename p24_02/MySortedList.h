#ifndef P24_02__MYSORTEDLIST_H_
#define P24_02__MYSORTEDLIST_H_

#include "MyList.h"
#include <functional>

template<typename T, class U = std::less<T>>
class MySortedList : public MyList<T> {
 public:
  MySortedList() = default;
  MySortedList(const std::initializer_list<T>& initializer_list) {
    for (const T& i: initializer_list)
      Insert(i);
  }
  void Insert(T value) {
    auto p_node = MyList<T>::First();
    if (p_node == nullptr) {
      MyList<T>::PushBack(value);
      return;
    }
    if (!comparator_(value, MyList<T>::First()->value)) {
      MyList<T>::PushFront(value);
      return;
    }
    while (p_node->next != nullptr && comparator_(value, p_node->next->value)) {
      p_node = p_node->next;
    }
    MyList<T>::InsertAfter(p_node, value);
  }
 private:
  U comparator_ = U();
};

#endif //P24_02__MYSORTEDLIST_H_
