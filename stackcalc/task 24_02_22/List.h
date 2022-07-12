#ifndef TASK_24_02_22_LIST_H
#define TASK_24_02_22_LIST_H

template<typename T>
class List {
protected:
    template<typename U>
    struct Node {
        U value;
        Node<U> *next;

        explicit Node(U _v, Node<U> *_n = nullptr) : value(_v), next(_n) {}
    };

    void InsertAfter(Node<T> *node, T value);

    int size = 0;
public:
    class Iterator {
    public:
        Node<T> *it_node;

        Iterator() : it_node(nullptr) {}

        explicit Iterator(Node<T> *it_node_) : it_node(it_node_) {}

        Iterator next() const {
            if (it_node != nullptr)
                return Iterator(it_node->next);
        }

        void operator++() {
            if (it_node != nullptr) it_node = it_node->next;
        }

        bool operator!=(const Iterator &it) const {
            return it_node != it.it_node;
        }

        T &operator*() {
            return it_node->value;
        }
    };

    Node<T> *first = nullptr;

    ~List() {
        while (first) {
            Node<T> *temp = first;
            first = first->next;
            delete temp;
            --size;
        }
    }

    void PushBack(T value);

    void RemoveAt(T value);

    T LastElement() const;

    void Print(std::ostream &out);

    void PushFront(T value);

    bool Empty() {
        return first == nullptr;
    }

    Iterator begin() const {
        return Iterator(first);
    }

    Iterator end() const {
        return Iterator(nullptr);// за последний
    }

};

template<typename T>
void List<T>::PushBack(T value) {
    if (first == nullptr) {
        first = new Node<T>(value);
    } else {
        Node<T> *current = first;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = new Node<T>(value);
        ++size;
    }
}

template<typename T>
void List<T>::RemoveAt(T value) {
    if (first == nullptr) {
        throw std::runtime_error("Is Empty");
    }
    if ((first->value) == value) { //////
        Node<T> *new_first = first->next;
        delete first;
        first = new_first;
    } else {
        Node<T> *current = first;
        while (current != nullptr && current->next != nullptr) {
            if (current->value != value && current->next->value == value) {
                Node<T> *to_delete = current->next;
                current->next = to_delete->next;
                delete to_delete;
                size--;
            }
            current = current->next;
        }
    }
}

template<typename T>
void List<T>::Print(std::ostream &out) {
    /*Node<T> *current = first;
    while (current != nullptr) {
        out << current->value << "  ";
        current = current->next;
    }*/
    for (T i: *this) {
      out << i << " ";
    }
//    for (Iterator it = begin(); it != end(); ++it) {
//        out << *it << " ";
//    }
}

template<typename T>
void List<T>::InsertAfter(List::Node<T> *node, T value) {
    if (node == nullptr) {
        PushBack(value);
    }
    Node<T> *current = new Node<T>(value);
    Node<T> *next = node->next;
    node->next = current;
    current->next = next;
}

template<typename T>
T List<T>::LastElement() const {
    Node<T> *current = first;
    while (current->next != nullptr) {
        current = current->next;
    }
    return current->value;
}

template<typename T>
void List<T>::PushFront(T value) {
    if (first == nullptr) {
        first = new Node<T>(value);
        return;
    }
    Node<T> *new_first = new Node<T>(value);
    new_first->next = first;
    first = new_first;
}


#endif //TASK_24_02_22_LIST_H
