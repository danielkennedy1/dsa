#include "AVLTree.h"
#include "TreeNode.h"
#include <algorithm>
#include <iostream>

template <typename T> void AVLTree<T>::insert(T val) {
    root = insert_rec(val, root);
}

template <typename T>
AVLNode<T> *AVLTree<T>::insert_rec(T val, AVLNode<T> *node) {
    if (node == nullptr) {
        return new AVLNode<T>(val);
    }

    if (node->val == val)
        return node;
    if (val < node->val)
        node->left = insert_rec(val, node->left);
    else if (val > node->val)
        node->right = insert_rec(val, node->right);

    node->height = 1 + std::max(height(node->left), height(node->right));

    int balance = balanceFactor(node);

    if (balance > 1) {
        if (val < node->left->val)
            return right(node);
        else {
            node->left = left(node->left);
            return right(node);
        }
    }

    if (balance < -1) {
        if (val > node->right->val)
            return left(node);
        else {
            node->right = right(node->right);
            return left(node);
        }
    }

    return node;
}

/*            Left
 *    A (node)        B
 *  /  \            /   \
 *  Al  B          A     C
 *    /   \  ->   / \   / \
 *   Bl   C      Al Bl Cl Cr
 *       / \
 *      Cl  Cr
 */

template <typename T> AVLNode<T> *AVLTree<T>::left(AVLNode<T> *node) {
    AVLNode<T> *B = node->right;
    AVLNode<T> *Bl = B->left;

    B->left = node;
    B->left->right = Bl;

    B->left->height = std::max(height(B->left->right), height(B->left->left));
    B->height = std::max(height(B->left), height(B->right));

    return B;
}
/*            Right
 *           A (node)         B
 *         /   \            /   \
 *        B     Ar         C     A
 *       / \        ->    / \   / \
 *      C   Br           Cl Cr Br Ar
 *     / \
 *    Cl  Cr
 *
 */

template <typename T> AVLNode<T> *AVLTree<T>::right(AVLNode<T> *node) {
    AVLNode<T> *B = node->left;
    AVLNode<T> *Br = B->right;

    B->right = node;
    B->right->left = Br;

    B->right->height =
        std::max(height(B->right->left), height(B->right->right));
    B->height = std::max(height(B->left), height(B->right));

    return B;
}

template <typename T> int AVLTree<T>::height(AVLNode<T> *node) {
    if (node == nullptr)
        return 0;
    return node->height;
}

template <typename T> int AVLTree<T>::balanceFactor(AVLNode<T> *node) {
    if (node == nullptr)
        return 0;
    return height(node->left) - height(node->right);
}

template <typename T> void AVLTree<T>::inorder(AVLNode<T> *root) {
    if (root != nullptr) {
        inorder(root->left);
        std::cout << "val: " << root->val << " b: " << balanceFactor(root)
                  << " h: " << root->height << std::endl;
        inorder(root->right);
    }
}
