#include <iostream>

#include "BinaryTree.h"
#include "TreeNode.h"

int main() {
    BinaryTree<int> *binaryTree = new BinaryTree<int>();

    binaryTree->root = new BinaryNode<int>(10);

    binaryTree->root->left = new BinaryNode<int>(5);

    binaryTree->root->right = new BinaryNode<int>(20);
    binaryTree->root->right->right = new BinaryNode<int>(30);

    std::cout << "Root val: " << binaryTree->root->val << std::endl;
    std::cout << "left val: " << binaryTree->root->left->val << std::endl;
    std::cout << "right val: " << binaryTree->root->right->val << std::endl;
    std::cout << "rightright val: " << binaryTree->root->right->right->val
              << std::endl;

    // NOTE: delete will only mark the memory as free and call destructor,
    // so we should redirect the pointer after we do this as anything else is
    // explicitly undefined behaviour
    delete binaryTree->root->right;
    binaryTree->root->right = nullptr;

    std::cout << "Root val: " << binaryTree->root->val << std::endl;
    std::cout << "left val: " << binaryTree->root->left->val << std::endl;
    std::cout << "right: " << binaryTree->root->right << std::endl;
    std::cout << "right val: " << binaryTree->root->right->val << std::endl;

    return 0;
}
