#ifndef TASK_24_02_22_SORTEDLIST_H
#define TASK_24_02_22_SORTEDLIST_H

#include <functional>

template<typename T, class U = std::greater<T>>
class SortedList : private List<T> {
public:
    void Insert(T value);

    using List<T>::Print;

    using List<T>::RemoveAt;

  using List<T>::begin;
  using List<T>::end;
private:
    U comparator = U();
};

template<typename T, class U>
void SortedList<T, U>::Insert(T value) {
    auto current = List<T>::first;
    if (current == nullptr) {
        List<T>::PushBack(value);
        return;
    }
    if (comparator(List<T>::first->value, value)) {
        List<T>::PushFront(value);
        return;
    }
    while (current->next != nullptr && !comparator(current->next->value, value)) {
        current = current->next;
    }
    List<T>::InsertAfter(current, value);
}

#endif //TASK_24_02_22_SORTEDLIST_H
