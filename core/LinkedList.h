#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "ListNode.h"

// MAYBE: store tail pointer

template <typename T> class LinkedList {
public:
  LinkedList(){};

  void append(T element) {
    ListNode<T> *newNode = new ListNode<T>(element);

    if (!head) {
      head = newNode;
      length++;
      return;
    }

    ListNode<T> *predecessor = head;

    while (predecessor->next) {
      predecessor = predecessor->next;
    }

    predecessor->next = newNode;

    length++;
  };

  T get(int index) {
    ListNode<T> *location = head;
    for (int i = 0; i < index; i++) {
      location = head->next;
    }
    return location->val;
  };

  void remove(int index);

  ListNode<T> *head = nullptr;
  int length = 0;
};

#endif
