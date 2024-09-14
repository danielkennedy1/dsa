#include <iostream>
#include "LinkedQueue.h"

int main() {
    LinkedQueue<float> stack = LinkedQueue<float>();
    stack.enqueue(1.0f);
    stack.enqueue(2.0f);
    stack.enqueue(3.0f);
    std::cout << stack.dequeue() << std::endl;
    std::cout << stack.dequeue() << std::endl;
    std::cout << stack.dequeue() << std::endl;


    stack.enqueue(4.0f);
    stack.enqueue(5.0f);
    std::cout << stack.dequeue() << std::endl;
    std::cout << stack.dequeue() << std::endl;
    std::cout << stack.dequeue() << std::endl;
    return 0;
}
