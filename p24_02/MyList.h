#ifndef P24_02__MYLIST_H_
#define P24_02__MYLIST_H_

#include <iostream>
#include <iterator>

template<typename T>
class MyList {
 protected:
  struct Node {
    T value;
    Node *next;
    explicit Node(int _v, Node *_n = nullptr) : value(_v), next(_n) {}
  };
  class Iterator {
    Node *node_;
   public:
    explicit Iterator(Node *node) : node_(node) {};
    Iterator operator++(int) {
      Iterator new_iter = Iterator(node_);
      node_ = node_->next;
      return new_iter;
    }
    Iterator &operator++() {
      node_ = node_->next;
      return *this;
    }
    bool operator==(const Iterator& other) const { return other.node_ == node_; }
    T &operator*() { return node_->value; }
    T operator*() const { return node_->value; }
   private:
  };
 public:
  MyList(const MyList<T> &) = delete;
  MyList() = default;
  MyList(const std::initializer_list<T>& initializer_list) {
    for (T i: initializer_list) {
      PushBack(i);
    }
  }
  MyList& operator=(const MyList<T>&) = delete;
  Iterator begin() { return Iterator(first_); }
  Iterator end() { return Iterator(nullptr); }
  virtual void Insert(T value) { PushBack(value); }
  virtual ~MyList() {
    while (first_) {
      DeleteElement(first_->value);
    }
  }
  void PushBack(T value) {
    if (first_ == nullptr) {
      first_ = new Node(value);
      last_ = first_;
    } else {
      last_->next = new Node(value);
      last_ = last_->next;
    }
  }
  bool DeleteElement(T value, bool all = true) {
    Node *s = first_;
    if (s == nullptr)
      return false;
    if (first_->value == value) {
      Node *newFirst = first_->next;
      delete first_;
      first_ = newFirst;
      return true;
    }
    while (s->next != nullptr && s != nullptr) {
      if (s->next->value == value) {
        EraseAfter(s);
        if (all)
          while (DeleteElement(value, all)) {}
        return true;
      }
      s = s->next;
    }
    return false;
  }
  void Print(std::ostream &out = std::cout) {
    for (T& i: *this) {
      out << i << " ";
    }
    out << std::endl;
  }
 protected:
  void PushFront(T value) {
    if (first_ == nullptr) {
      PushBack(value);
      return;
    }
    Node *new_first = new Node(value, first_);
    first_ = new_first;
  }
  void EraseAfter(Node *node) {
    if (node == nullptr || node == last_) {
      return;
    }
    if (node->next == last_) {
      last_ = node;
      delete node->next;
      node->next = nullptr;
    } else {
      Node *newNext = node->next->next;

      delete node->next;
      node->next = newNext;
    }
  }
  void InsertAfter(Node *node, T value) {
    if (node == last_) {
      node->next = new Node(value);
      last_ = node->next;
    } else {
      Node *next = node->next;
      node->next = new Node(value, next);
    }
  }
  Node *First() const { return first_; }
  Node *Last() const { return last_; }
 private:
  Node *first_ = nullptr;
  Node *last_ = nullptr;
};

#endif //P24_02__MYLIST_H_
