#ifndef TASK_24_02_22_STACKONLIST_H
#define TASK_24_02_22_STACKONLIST_H

#include"List.h"

template<typename T>
class StackOnList : protected List<T> {
public:
    void Push(T value) {
      List<T>::PushFront(value);
    }

    T Top() const {
      return List<T>::first->value;
    }

    void Pop() {
      List<T>::RemoveAt(Top());
    }

    using List<T>::Print;

    using List<T>::Empty;

};


#endif //TASK_24_02_22_STACKONLIST_H
