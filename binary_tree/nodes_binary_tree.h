#ifndef BINARY_TREE_NODES_BINARY_TREE_H
#define BINARY_TREE_NODES_BINARY_TREE_H

#include <iostream>

template<typename T>
class Node {
public:
    explicit Node(T key) : Key(key) {

    }

    T Key;
    T Value;
    Node *Left = nullptr;
    Node *Right = nullptr;

};

template<typename T>
class nodes_binary_tree {
public:
    nodes_binary_tree() : Root(nullptr) {

    }

    ~nodes_binary_tree() {
        cleanse(Root);
    }

    void Insert(T key, T value) {
        insert(key, value, Root);
    }

    void Prefix() {
        prefix(Root);
    }

    void Infix() {
        infix(Root);
    }

    void Postfix() {
        postfix(Root);
    }

private:
    Node<T> *Root;

    void insert(T key, T value, Node<T> *&node);

    void cleanse(Node<T> *node);

    void prefix(Node<T> *current);

    void infix(Node<T> *current);

    void postfix(Node<T> *current);
};

template<typename T>
void nodes_binary_tree<T>::insert(T key, T value, Node<T> *&node) {
    if (node == nullptr) {
        node = new Node<T>(key);
        node->Key = key;
        node->Value = value;
        node->Left = node->Right = nullptr;
        return;
    }
    if (key < node->Key) {
        insert(key, value, node->Left);
    } else { /// (key >= node->Key)
        insert(key, value, node->Right);
    }
}

template<typename T>
void nodes_binary_tree<T>::cleanse(Node<T> *node) {
    if (node == nullptr) return;
    cleanse(node->Left);
    cleanse(node->Right);
    delete node;
}

template<typename T>
void nodes_binary_tree<T>::prefix(Node<T> *current) {
    if (current == nullptr) return;
    std::cout << current->Key << " ";
    std::cout << std::endl;
    prefix(current->Left);
    std::cout << std::endl;
    prefix(current->Right);
}

template<typename T>
void nodes_binary_tree<T>::infix(Node<T> *current) {
    if (current == nullptr) return;
    infix(current->Left);
    std::cout << std::endl;
    std::cout << current->Key << " ";
    std::cout << std::endl;
    infix(current->Right);
}

template<typename T>
void nodes_binary_tree<T>::postfix(Node<T> *current) {
    if (current == nullptr) return;
    postfix(current->Left);
    postfix(current->Right);
    std::cout << std::endl;
    std::cout << current->Key << " ";
    std::cout << std::endl;
}


#endif //BINARY_TREE_NODES_BINARY_TREE_H
