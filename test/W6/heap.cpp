#include "Heap.hpp"

int main() {
    Heap<int> *heap = new Heap<int>();

    heap->insert(1, 1);
    heap->insert(5, 5);
    heap->insert(6, 6);
    heap->insert(2, 2);
    heap->insert(4, 4);
    heap->insert(3, 3);
    heap->insert(7, 7);
    
    while (heap->array->length >= 1) {
        std::cout << heap->min() << std::endl;
    }

    return 0;
}
