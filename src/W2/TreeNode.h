#ifndef TREENODE_H 
#define TREENODE_H

template <typename T> struct BinaryNode {
  T val;
  BinaryNode *left;
  BinaryNode *right;
  BinaryNode(T x) : val(x), left(nullptr), right(nullptr) {};
  ~BinaryNode<T>() {};
};

#endif
