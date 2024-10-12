#include "AVLTree.h"

int main() {
    AVLTree<int> *avlTree = new AVLTree<int>();

    avlTree->insert(10);
    avlTree->insert(20);
    avlTree->insert(30);
    avlTree->insert(40);
    avlTree->insert(50);
    avlTree->insert(60);
    avlTree->insert(70);

    avlTree->inorder(avlTree->root);
}
