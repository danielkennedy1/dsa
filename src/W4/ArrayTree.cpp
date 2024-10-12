#include "ArrayTree.h"

template <typename T> int ArrayTree<T>::left(int nodeIndex) {
    return nodeIndex * 2 + 1;
}

template <typename T> int ArrayTree<T>::right(int nodeIndex) {
    return nodeIndex * 2 + 2;
}

template <typename T> int ArrayTree<T>::parent(int nodeIndex) {
    if (nodeIndex == 0)
        return 0;
    return (nodeIndex - 1) / 2;
}

template <typename T> void ArrayTree<T>::insert(T val) {
    int nodeIndex = 0;
    if
}
