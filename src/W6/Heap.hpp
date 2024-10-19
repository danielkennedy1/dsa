#include "ArrayList.h"
#include <cmath>

template <typename T> struct HeapNode {
    T value;
    int priority;
    HeapNode(T value, int priority) : value(value), priority(priority) {};
};

template <typename T> class Heap {
public:
    Heap() {
        array = new ArrayList<HeapNode<T>*>();
    }

    //TODO: There's a faster way to do it by shifting the replaced value down instead of this percolation
    void insert(T newValue, int priority) {
        array->append(new HeapNode<T>(newValue, priority));

        int childIndex = array->length - 1;
        int parentIndex = static_cast<int>(std::floor((static_cast<double>(childIndex) - 1.0) / 2.0));

        while(childIndex > 0 && array->get(parentIndex)->priority > array->get(childIndex)->priority) {
            swap(parentIndex, childIndex);
            childIndex = parentIndex;
            parentIndex = static_cast<int>(std::floor((static_cast<double>(childIndex) - 1.0) / 2.0));
        }
    }

    ArrayList<HeapNode<T>*>* array;


    void swap(int indexA, int indexB) {
        HeapNode<T>* t = array->get(indexA);
        array->get(indexA) = array->get(indexB);
        array->get(indexB) = t;
    }

};
