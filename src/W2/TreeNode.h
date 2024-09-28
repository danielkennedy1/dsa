#ifndef TREENODE_H 
#define TREENODE_H

#include <iostream>

template <typename T> struct BinaryNode {
  T val;
  BinaryNode** edgeIn;
  BinaryNode *left;
  BinaryNode *right;
  BinaryNode(T val, BinaryNode** edgeIn) : val(val), edgeIn(edgeIn), left(nullptr), right(nullptr) {};
  ~BinaryNode() {
    *this->edgeIn = nullptr;
    if (left != nullptr) delete left;
    if (right != nullptr) delete right;
  };
};

template <typename T> struct AVLNode {
  T val;
  int height;
  AVLNode* left;
  AVLNode* right;

  AVLNode(T val) : val(val), left(nullptr), right(nullptr), height(1) {};
  ~AVLNode() {
    if (left != nullptr) delete left;
    if (right != nullptr) delete right;
  }
};

#endif
