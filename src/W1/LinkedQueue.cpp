#include "LinkedQueue.h"
#include "ListNode.h"

template <typename T> void LinkedQueue<T>::enqueue(T val) {
  ListNode<T>* newNode = new ListNode<T>(val);

  if (head == nullptr) {
    head = newNode;
    tail = newNode;
  }

  head->prev = newNode;
  newNode->next = head;
  head = newNode;
};

template <typename T> T LinkedQueue<T>::dequeue(){
  if (tail == nullptr) return -1; // for now
  T returnVal = tail->val;
  ListNode<T>* oldTail = tail;
  if (head == tail) head = nullptr;
  tail = tail->prev;
  delete oldTail;
  return returnVal;
};
