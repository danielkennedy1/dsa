#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H

#include "ListNode.h"

template <typename T> class LinkedStack {
public:
  T peek(); 
  void push(T newVal); 
  T pop(); 

  ListNode<T> *head = nullptr;
};

#include "LinkedStack.cpp"

#endif
