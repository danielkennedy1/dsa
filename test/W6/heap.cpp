#include "Heap.hpp"

int main() {
    Heap<int>* heap = new Heap<int>();

    heap->insert(69, 20);
    heap->insert(420, 10);
    heap->insert(30000, 2);


    for(int i = 0; i < heap->array->length; i++) std::cout << heap->array->get(i)->value << ":" << heap->array->get(i)->priority << ", ";

    std::cout << std::endl;

    return 0;
}
