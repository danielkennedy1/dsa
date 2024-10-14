#include "ArrayList.h"
#include <cstdint>

#define HASH_SIZE 4951

template <typename T> struct ChainNode {
    T element;
    ChainNode *next = nullptr;
    ChainNode<T>(T element) : element(element){};
};

template <typename T> class ChainingHashTable {
public:
    ChainNode<T> *table[HASH_SIZE];

    ChainingHashTable() {
        // Produces some interesting errors when you don't zero the memory
        //for (int i = 0; i < HASH_SIZE; i++) {
        //    table[i] = nullptr;
        //}
    };

    void insert(T element) {
        if (lookup(element) == nullptr) {
            ChainNode<T> *node = new ChainNode<T>(element);
            table[hash(element)] = node;
        } else {
            ChainNode<T> *node = table[hash(element)];
            while (node->next != nullptr) {
                node = node->next;
            }
            ChainNode<T> *newNode = new ChainNode<T>(element);
            node->next = newNode;
        }
    };

    T *lookup(T element) {
        ChainNode<T> *node = table[hash(element)];
        while (node != nullptr) {
            if (node->element == element) {
                return &node->element;
            }
            node = node->next;
        }
        return nullptr;
    };

    ArrayList<T *> all() {
        ArrayList<T *> all;
        for (int i = 0; i < HASH_SIZE; i++) {
            ChainNode<T> *node = table[i];
            while (node != nullptr) {
                all.append(&node->element);
                node = node->next;
            }
        }
        return all;
    };

    // Paul Larson's (Microsoft Research) hash function
    unsigned int hash(const T &element) {
        const char *s = reinterpret_cast<const char *>(&element);
        uint64_t result = 0;
        for (size_t i = 0; i < sizeof(element); ++i) {
            result = result * 101 + s[i];
        }
        return result % HASH_SIZE;
    };
};
