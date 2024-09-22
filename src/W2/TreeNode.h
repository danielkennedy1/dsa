#ifndef TREENODE_H 
#define TREENODE_H

#include <iostream>

template <typename T> struct BinaryNode {
  T val;
  BinaryNode *left;
  BinaryNode *right;
  BinaryNode(T x) : val(x), left(nullptr), right(nullptr) {};
  ~BinaryNode<T>() {
    std::cout << "in treenode destructor for val " << val << std::endl;
    if (left != nullptr) delete left;
    if (right != nullptr) delete right;
  };
};

#endif
