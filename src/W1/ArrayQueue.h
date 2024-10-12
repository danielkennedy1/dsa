#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H

#include "ArrayList.h"

template <typename T> class ArrayQueue {
public:
    ArrayQueue<T>() { array = new T[size]; };
    void enqueue(T val);
    T dequeue();

    int front = 0;
    int length = 0;

    int size = 1;
    T *array;
    void resize(int newSize);
};

#include "ArrayQueue.cpp"

#endif
