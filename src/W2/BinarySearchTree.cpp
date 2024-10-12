#include "BinarySearchTree.h"
#include "TreeNode.h"

template <typename T> void BinarySearchTree<T>::insert(T val) {
    return insert_rec(val, root);
}

// reference to a pointer, btw
template <typename T>
void BinarySearchTree<T>::insert_rec(T val, BinaryNode<T> *&node) {
    if (node == nullptr) {
        node = new BinaryNode<T>(val, &node);
        return;
    }
    if (node->val == val)
        return;
    if (node->val > val)
        return insert_rec(val, node->left);
    return insert_rec(val, node->right);
}

template <typename T> bool BinarySearchTree<T>::lookup(T val) {
    return locate(val) != nullptr;
}

template <typename T> T BinarySearchTree<T>::findMin() {
    BinaryNode<T> *node = findMinNode(root);
    if (node == nullptr)
        return -1;
    return node->val;
}

template <typename T>
BinaryNode<T> *BinarySearchTree<T>::findMinNode(BinaryNode<T> *node) {
    while (node != nullptr && node->left != nullptr)
        node = node->left;
    return node;
}

template <typename T> T BinarySearchTree<T>::findMax() {
    BinaryNode<T> *node = findMaxNode(root);
    if (node == nullptr)
        return -1;
    return node->val;
}

template <typename T>
BinaryNode<T> *BinarySearchTree<T>::findMaxNode(BinaryNode<T> *node) {
    while (node != nullptr && node->right != nullptr)
        node = node->right;
    return node;
}

template <typename T> void BinarySearchTree<T>::remove(T val) {
    removeNode(locate(val));
}

template <typename T>
void BinarySearchTree<T>::removeNode(BinaryNode<T> *node) {
    if (node == nullptr)
        return;
    if (node->left == nullptr && node->right == nullptr) {
        delete node;
        return;
    }

    if (node->left != nullptr && node->right == nullptr) {
        node->val = node->left->val;
        removeNode(node->left);
        return;
    }

    if (node->left == nullptr && node->right != nullptr) {
        node->val = node->right->val;
        removeNode(node->right);
        return;
    }

    BinaryNode<T> *M = findMinNode(node->right);
    node->val = M->val;
    removeNode(M);
}

template <typename T> BinaryNode<T> *BinarySearchTree<T>::locate(T val) {
    BinaryNode<T> *node = root;
    while (node != nullptr) {
        if (node->val == val)
            return node;
        if (node->val > val) {
            node = node->left;
        } else {
            node = node->right;
        }
    }
    return nullptr;
}
