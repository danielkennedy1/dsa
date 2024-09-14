#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

#include "ListNode.h"

template <typename T>
class LinkedQueue {
public:
  LinkedQueue<T>() {};
  void enqueue(T val);
  T dequeue();
  
  ListNode<T>* head = nullptr;
  ListNode<T>* tail = nullptr;
};

#include "LinkedQueue.cpp"

#endif
