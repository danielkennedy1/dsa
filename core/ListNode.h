#ifndef LISTNODE_H
#define LISTNODE_H

#include <iostream>

template <typename T> struct ListNode {
  T val;
  ListNode *next;
  ListNode(T x) : val(x), next(nullptr){};
  ~ListNode<T>() {};
};

#endif
