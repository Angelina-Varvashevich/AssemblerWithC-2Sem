#ifndef P24_02__STACK_H_
#define P24_02__STACK_H_

#include "MyList.h"

template<typename T>
class Stack : private MyList<T>{
 public:
  T Pop() {
    this->DeleteElement(this->First()->value, false);
  }
  void Push(T value) {
    this->PushFront(value);
  }
  T Top() const {
    return this->First()->value;
  }
  [[nodiscard]] bool IsEmpty() const {
    return this->First() == this->Last();
  }
};

#endif //P24_02__STACK_H_
