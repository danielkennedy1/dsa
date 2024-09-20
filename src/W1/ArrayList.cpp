#include "ArrayList.h"
#include <iostream>

template <typename T> void ArrayList<T>::append(T element) {
  if (length == size)
    resize(size << 1);
  array[length] = element;
  length++;
}

template <typename T> void ArrayList<T>::insert(T element, int index) {
  if (length == size)
    resize(size << 1);

  if (index == length) {
    append(element);
    return;
  }

  if (index > length || index < 0) {
    std::cout << "invalid insertion to arraylist of size " << size << " length " << length << " at index " << index << std::endl;
    return;
  }

  for (int i = index + 1; i < length; i++) {
    array[i] = array[i - 1];
  }

  array[index] = element;

  length++;
}

template <typename T> T ArrayList<T>::get(int index) { return array[index]; }

template <typename T> void ArrayList<T>::resize(int newSize) {
  T *newArray = new T[newSize];

  for (int i = 0; i < size; i++) {
    newArray[i] = array[i];
  }
  size = newSize;
  delete[] array;
  array = newArray;
}

template <typename T> void ArrayList<T>::remove(int index) {
  length--;
  for (int i = index; i < length; i++)
    array[i] = array[i + 1];
}

template <typename T> void ArrayList<T>::clear() { length = 0; }
