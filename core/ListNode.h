#ifndef LISTNODE_H
#define LISTNODE_H

template<typename T>
struct ListNode {
    T val;
    ListNode *next;
    ListNode(T x) : val(x), next(nullptr) {}
};

#endif
