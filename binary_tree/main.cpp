#include <iostream>
#include "nodes_binary_tree.h"
#include "array_binary_tree.h"

int main() {
    nodes_binary_tree<int> bt;
    bt.Insert(4, 1);
    bt.Insert(-13, 1);
    bt.Insert(13, 1);
    bt.Insert(-18, 1);
    bt.Insert(-9, 1);
    bt.Insert(-19, 1);
    bt.Insert(-15, 1);

    std::cout << std::endl;
    bt.Prefix();
    std::cout << "inf" << std::endl;
    bt.Infix();
    std::cout << "Postfix" << std::endl;
    bt.Postfix();

    array_binary_tree at;
    /*at.Insert(8, 1);
    at.Insert(-13,1);
    at.Insert(13,1);
    at.Insert(-15,1);
    at.Insert(-9,1);
    at.Insert(15,1);
    at.Insert(-29,1);*/

    at.Insert(4, 1);
    at.Insert(-13, 1);
    at.Insert(13, 1);
    at.Insert(-18, 1);
    at.Insert(-9, 1);
    at.Insert(-19, 1);
    at.Insert(-15, 1);

    std::cout << "-----------" << std::endl;
    at.Tree_in_array();
    std::cout << std::endl;
    std::cout << "Prefix" << std::endl;
    at.Prefix();
    std::cout << "Infix" << std::endl;
    at.Infix();
    std::cout << "Postfix" << std::endl;
    at.Postfix();


    return 0;
}
