#include "LinkedList.h"

template <typename T> void LinkedList<T>::append(T element) {
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

template <typename T>
T LinkedList<T>::get(int index) {
  ListNode<T> *location = head;
  for (int i = 0; i < index; i++) {
    location = head->next;
  }
  return location->val;
};
