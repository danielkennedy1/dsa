#include "ListNode.h"

template<typename T>
class Stack {
public:
    T peek() {
        if (head == nullptr) {
            exit(1);
        }
        return head->val;
    }
    
    void push(T newVal) {
        ListNode<T>* newNode = new ListNode<T>(newVal);
        newNode->next = head;
        head = newNode;
    }

    T pop() {
        if (head == nullptr) {
            exit(1);
        }
        T returnVal = head->val;
        head = head->next;
        return returnVal;
    }
    ListNode<T>* head = nullptr;
};
