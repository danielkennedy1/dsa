#include "HashTable.h"

template <typename T> void HashTable<T>::insert(T val) {
  table[val % HASH_SIZE] = val;
  
}
