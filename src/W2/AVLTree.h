#ifndef AVLTREE_H
#define AVLTREE_H

#include "TreeNode.h"

template <typename T> class AVLTree {
public:
    AVLNode<T> *root;
    void insert(T val);
    AVLTree<T>() : root(nullptr){};
    void inorder(AVLNode<T> *node);

private:
    AVLNode<T> *insert_rec(T val, AVLNode<T> *node);
    int balanceFactor(AVLNode<T> *node);
    int height(AVLNode<T> *node);
    AVLNode<T> *left(AVLNode<T> *node);
    AVLNode<T> *right(AVLNode<T> *node);
};

#include "AVLTree.cpp"

#endif
