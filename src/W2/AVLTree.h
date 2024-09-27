#ifndef AVLTREE_H
#define AVLTREE_H

#include "TreeNode.h"

template <typename T> class AVLTree {
public:
  AVLNode<T>* root;
  void insert(T val);
};

#endif
