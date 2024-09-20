#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include "ArrayList.h"
template <typename T> class ArrayStack {
public:
  ArrayStack<T>() : arrayList() {};
  T peek();
  void push(T newVal);
  T pop();
  ArrayList<T> arrayList;
};

#include "ArrayStack.cpp"
#endif
