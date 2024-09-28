#ifndef HASHTABLE_H
#define HASHTABLE_H

#define HASH_SIZE 101

template <typename T> class HashTable {
public:
  void insert(T val);
  bool lookup(T val);
  T table[HASH_SIZE];
  HashTable<T>() {};
  
};
#include "HashTable.cpp"
#endif
