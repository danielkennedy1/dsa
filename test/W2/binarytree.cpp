#include <iostream>

#include "TreeNode.h"
#include "BinaryTree.h"

int main() {
  BinaryTree<int>* binaryTree = new BinaryTree<int>();

  binaryTree->root = new BinaryNode<int>(10);

  binaryTree->root->left = new BinaryNode<int>(5);

  binaryTree->root->right = new BinaryNode<int>(20);

  std::cout << "Root val: " << binaryTree->root->val << std::endl;
  std::cout << "left val: " << binaryTree->root->left->val << std::endl;
  std::cout << "right val: " << binaryTree->root->right->val << std::endl;

  return 0;
}
