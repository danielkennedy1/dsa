#include <iostream>
#include "ArrayQueue.h"

template <typename T>
void printQueue(ArrayQueue<T> queue){

  std::cout << "array: ";
  for(int i = 0; i < queue.size; i++) std::cout << queue.array[i];
  std::cout << " size: " << queue.size;
  std::cout << " length: " << queue.length;
  std::cout << " front: " << queue.front;
  std::cout << std::endl;
}

int main() {
    ArrayQueue<float> queue = ArrayQueue<float>();
    queue.enqueue(1.0f);
    queue.enqueue(2.0f);
    queue.enqueue(3.0f);

    std::cout << queue.dequeue() << std::endl;
    std::cout << queue.dequeue() << std::endl;
    std::cout << queue.dequeue() << std::endl;

    printQueue(queue);

    queue.enqueue(4.0f);
    queue.enqueue(5.0f);
    std::cout << queue.dequeue() << std::endl;
    std::cout << queue.dequeue() << std::endl;
    std::cout << queue.dequeue() << std::endl;

    
    return 0;
}
