#ifndef TREENODE_H 
#define TREENODE_H

#include <iostream>

template <typename T> struct BinaryNode {
  T val;
  BinaryNode<T>** edgeIn;
  BinaryNode *left;
  BinaryNode *right;
  BinaryNode(T x, BinaryNode<T>** edgeIn) : val(x), edgeIn(edgeIn), left(nullptr), right(nullptr) {};
  ~BinaryNode<T>() {
    *this->edgeIn = nullptr;
    if (left != nullptr) delete left;
    if (right != nullptr) delete right;
  };
};

#endif
