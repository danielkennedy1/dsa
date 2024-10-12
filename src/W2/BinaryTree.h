#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "TreeNode.h"

template <typename T> class BinaryTree {
public:
    BinaryNode<T> *root;
    BinaryTree<T>() : root(nullptr){};
};

#endif
