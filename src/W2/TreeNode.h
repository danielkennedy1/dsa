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
  int balanceFactor;
  AVLNode** edgeIn;
  AVLNode* left;
  AVLNode* right;

  AVLNode(T val, AVLNode** edgeIn) : val(val), edgeIn(edgeIn), left(nullptr), right(nullptr), balanceFactor(0) {};
  ~AVLNode() {
    *this->edgeIn = nullptr;
    if (left != nullptr) delete left;
    if (right != nullptr) delete right;
  }
};

#endif
