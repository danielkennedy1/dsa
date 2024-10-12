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

template <typename T> T LinkedList<T>::get(int index) {
    ListNode<T> *location = head;

    while (index-- > 0)
        location = location->next;

    return location->val;
};

template <typename T> void LinkedList<T>::remove(int index) {
    if (index >= length)
        return; // say nothin'

    ListNode<T> *predecessor = nullptr;
    ListNode<T> *node = head;

    while (index-- > 0) {
        predecessor = node;
        node = node->next;
    }

    if (predecessor == nullptr)
        head = node->next;
    else
        predecessor->next = node->next;

    delete node;

    length--;
};

template <typename T> void LinkedList<T>::insert(T element, int index) {
    if (index >= length || index < 0)
        return;

    ListNode<T> *newNode = new ListNode<T>(element);

    if (!head) {
        head = newNode;
        length++;
        return;
    }

    ListNode<T> *predecessor = nullptr;
    ListNode<T> *successor = head;

    while (index-- > 0) {
        predecessor = successor;
        successor = successor->next;
    }

    if (!predecessor) {
        head = newNode;
        newNode->next = successor;
    } else {
        predecessor->next = newNode;
        newNode->next = successor;
    }

    length++;
};

template <typename T> void LinkedList<T>::clear() {
    ListNode<T> *node = head;
    ListNode<T> *next = nullptr;

    while (node) {
        next = node->next;
        delete node;
        node = next;
    }

    length = 0;
};
