#ifndef LISTNODE_H
#define LISTNODE_H

template <typename T> struct ListNode {
    T val;
    ListNode *next;
    ListNode *prev;
    ListNode(T x) : val(x), next(nullptr), prev(nullptr) {};
    ~ListNode() {};
};

#endif
