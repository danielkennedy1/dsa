#include "ArrayQueue.h"

template <typename T> void ArrayQueue<T>::enqueue(T val) {
  if (length == size) resize(size << 1);
  array[(front + length) % size] = val;
  length++;
}

template <typename T> T ArrayQueue<T>::dequeue() {
  if (length == 0) return -1;
  T returnVal = array[front];
  front = ++front % size;
  length--;
  return returnVal;
}

template <typename T> void ArrayQueue<T>::resize(int newSize) {
  T *newArray = new T[newSize];

  for (int i = 0; i < size; i++) {
    newArray[i] = array[(front + i) % length];
  }

  size = newSize;
  delete[] array;
  array = newArray;

  front = 0;
}
