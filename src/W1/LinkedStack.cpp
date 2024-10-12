#include "LinkedStack.h"

template <typename T> T LinkedStack<T>::peek() {
    if (head == nullptr) {
        exit(1);
    }
    return head->val;
}

template <typename T> void LinkedStack<T>::push(T newVal) {
    ListNode<T> *newNode = new ListNode<T>(newVal);
    newNode->next = head;
    head = newNode;
}

template <typename T> T LinkedStack<T>::pop() {
    if (head == nullptr) {
        exit(1);
    }
    T returnVal = head->val;
    head = head->next;
    return returnVal;
}
