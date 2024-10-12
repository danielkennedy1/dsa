#ifndef SIMPLEHASHTABLE_H
#define SIMPLEHASHTABLE_H

#define HASH_SIZE 101

template <typename T> class SimpleHashTable {
public:
    void insert(T val);
    bool lookup(T val);
    T table[HASH_SIZE];
    SimpleHashTable<T>(){};
};
#include "SimpleHashTable.cpp"
#endif
