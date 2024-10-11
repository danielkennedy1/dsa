#ifndef ARRAYTREE_H
#define ARRAYTREE_H

#include "ArrayList.h"

template <typename T> class ArrayTree {
public:
  ArrayList<T>* list;
  ArrayTree<T> () : list(new ArrayList<T>()) {};
  int root = 0;
  int left(int nodeIndex);
  int right(int nodeIndex);
  int parent(int nodeIndex); 
  void insert(T val);

};

#include "ArrayTree.cpp"

#endif
