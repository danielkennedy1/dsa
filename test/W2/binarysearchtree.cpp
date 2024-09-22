#include <cassert>
#include <iostream>

#include "BinarySearchTree.h"


int main() {
  BinarySearchTree<int>* tree = new BinarySearchTree<int>();
  std::cout << "instantiated, inserting:" << std::endl;
  tree->insert(5); // root
  tree->insert(2); // left
  tree->insert(10); // right
  tree->insert(6); // right left

  std::cout << "Ordering assersions" << std::endl;
  assert(tree->root->val == 5);
  assert(tree->root->left->val == 2);
  assert(tree->root->right->val == 10);

  std::cout << "lookup assertion" << std::endl;
  assert(tree->lookup(10));

  std::cout << "findMin & findMax" << std::endl;
  assert(tree->findMin() == 2);
  assert(tree->findMax() == 10);

  std::cout << "Remove" << std::endl;
  tree->remove(5);
  //min node of right subtree = right left
  assert(tree->root->val == 6);
  tree->remove(6);
  //min node of right subtree = right node
  assert(tree->root->val == 10);
  tree->remove(10);
  //only left node remains
  assert(tree->root->val == 2);
  tree->remove(2);
  // no nodes remain
  assert(tree->root == nullptr);

  return 0;
}
