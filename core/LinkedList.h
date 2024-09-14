#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "ListNode.h"

// TODO: this has literally no error handling

template <typename T> class LinkedList {
public:
  LinkedList(){};

  void append(T element);
  void insert(T element, int index);
  T get(int index);
  void remove(int index);
  void clear();

  ListNode<T> *head = nullptr;
  int length = 0;
};

#include "LinkedList.cpp"

#endif
