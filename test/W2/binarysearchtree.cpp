#include <cassert>
#include <iostream>

#include "BinarySearchTree.h"


int main() {
  BinarySearchTree<int>* tree = new BinarySearchTree<int>();
  std::cout << "instantiated, inserting:" << std::endl;
  tree->insert(5); // root
  tree->insert(2); // left
  tree->insert(10); // right


  std::cout << "Ordering assersions" << std::endl;
  assert(tree->root->val == 5);
  assert(tree->root->left->val == 2);
  assert(tree->root->right->val == 10);

  std::cout << "lookup assertion" << std::endl;
  assert(tree->lookup(10));

  return 0;
}
