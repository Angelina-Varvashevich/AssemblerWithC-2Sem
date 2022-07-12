#include "array_binary_tree.h"

void array_binary_tree::insert(int key, int value, int index) {
    resize_if_overflow(index);
    if (nodes_array[index].key == null_ && nodes_array[index].value == null_) {
        nodes_array[index].key = key;
        nodes_array[index].value = value;
        return;
    }
    if (key < nodes_array[index].key) {
        insert(key, value, 2 * index + 1);
    } else {
        insert(key, value, 2 * index + 2);
    }

}

void array_binary_tree::prefix(int index) {
    if (nodes_array[index].key == null_ && nodes_array[index].value == null_) return;
    std::cout << nodes_array[index].key << " " << std::endl;
    std::cout << std::endl;
    prefix(2 * index + 1);
    prefix(2 * index + 2);
}

void array_binary_tree::infix(int index) {
    if (nodes_array[index].key == null_ && nodes_array[index].value == null_) return;
    infix(2 * index + 1);
    std::cout << nodes_array[index].key << " " << std::endl;
    std::cout << std::endl;
    infix(2 * index + 2);
}

void array_binary_tree::postfix(int index) {
    if (nodes_array[index].key == null_ && nodes_array[index].value == null_) return;
    postfix(2 * index + 1);
    postfix(2 * index + 2);
    std::cout << nodes_array[index].key << " " << std::endl;
    std::cout << std::endl;
}

void array_binary_tree::resize_if_overflow(int index) {
    if (size <= 2 * index + 2) {
        array_node *new_nodes_array = new array_node[size * increase];
        int current_size=size;
        for (int i = 0; i < size; ++i) {
            new_nodes_array[i].key = nodes_array[i].key;
            new_nodes_array[i].value = nodes_array[i].value;
        }
        delete[] nodes_array;
        nodes_array = new_nodes_array;
        size *= increase;
        for (int i=current_size; i<size; ++i){
            new_nodes_array[i].key =null_;
            new_nodes_array[i].value = null_;
        }


    }
}

