#include <iostream>
#include "LinkedQueue.h"

int main() {
    LinkedQueue<float> queue = LinkedQueue<float>();
    queue.enqueue(1.0f);
    queue.enqueue(2.0f);
    queue.enqueue(3.0f);
    std::cout << queue.dequeue() << std::endl;
    std::cout << queue.dequeue() << std::endl;
    std::cout << queue.dequeue() << std::endl;


    queue.enqueue(4.0f);
    queue.enqueue(5.0f);
    std::cout << queue.dequeue() << std::endl;
    std::cout << queue.dequeue() << std::endl;
    std::cout << queue.dequeue() << std::endl;
    return 0;
}
