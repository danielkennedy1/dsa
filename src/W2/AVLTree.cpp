#include "AVLTree.h"

template <typename T> void AVLTree<T>::insert(T val) {
  AVLNode<T>* node = root;
  while(node != nullptr) {
    if (val < node->val) {
      node->balanceFactor++;
      node = node->left;
    } else {
      node->balanceFactor--;
      node = node->left;
    }
  }


}


