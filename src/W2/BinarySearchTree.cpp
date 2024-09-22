#include "BinarySearchTree.h"
#include "TreeNode.h"

template <typename T> void BinarySearchTree<T>::insert(T val) { 
    return insert_rec(val, root);
}

// reference to a pointer, btw
template <typename T> void BinarySearchTree<T>::insert_rec(T val, BinaryNode<T>*& node) { 
  if (node == nullptr) {
    node = new BinaryNode<T>(val);
    return;
  }
  if (node->val == val) return;
  if (node->val > val) return insert_rec(val, node->left);
  return insert_rec(val, node->right);
}

template <typename T> bool BinarySearchTree<T>::lookup(T val) {
  BinaryNode<T>* node = root;
  while (node != nullptr) {
    if (node->val == val) return true;
    if (node->val > val) node = node->left;
    else node = node->right;
  }
  return false;
}
