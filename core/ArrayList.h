#ifndef ARRAYLIST_H
#define ARRAYLIST_H

template <typename T> class ArrayList {
public:
  ArrayList() { array = new T[size]; };

  void append(T element);
  void insert(T element, int index);
  T get(int index);
  void remove(int index);
  void clear();

  int size = 1; // size of array
  int length = 0;  // number of elements

  T *array;

  void resize(int newSize);
};

#include "ArrayList.cpp"

#endif
