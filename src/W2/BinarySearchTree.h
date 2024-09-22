#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "TreeNode.h"

// NOTE: This is a no-duplicates implementation
template<typename T> class BinarySearchTree {
public:
  BinaryNode<T>* root;
  BinarySearchTree<T> () : root(nullptr) {};
  void insert(T val);
  bool lookup(T val);
  T findMin();
  BinaryNode<T>* findMinNode(BinaryNode<T>* node);
  T findMax();
  BinaryNode<T>* findMaxNode(BinaryNode<T>* node);
  void remove(T val);

private:
  void insert_rec(T val, BinaryNode<T>*& node);
  BinaryNode<T>* locate(T val);
};

#include "BinarySearchTree.cpp"

#endif
