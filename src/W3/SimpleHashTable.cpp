#include "SimpleHashTable.h"

template <typename T> void SimpleHashTable<T>::insert(T val) {
    table[val % HASH_SIZE] = val;
}
