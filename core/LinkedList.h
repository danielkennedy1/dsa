#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "ListNode.h"

// MAYBE: store tail pointer

template <typename T> class LinkedList {
public:
  LinkedList(){};

  void append(T element);

  T get(int index);

  void remove(int index);

  ListNode<T> *head = nullptr;
  int length = 0;
};

#include "LinkedList.cpp"

#endif
