#include "ArrayStack.h"

template <typename T> T ArrayStack<T>::peek() {
  return arrayList.get(arrayList.length - 1);
};

template <typename T> void ArrayStack<T>::push(T newVal) {
  arrayList.append(newVal);
};

template <typename T> T ArrayStack<T>::pop() {
  T returnVal = arrayList.get(arrayList.length - 1);
  arrayList.remove(arrayList.length - 1);
  return returnVal;
};
