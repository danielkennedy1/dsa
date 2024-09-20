#include <iostream>
#include "LinkedStack.h"

int main() {
    LinkedStack<float> stack = LinkedStack<float>();
    stack.push(1.0f);
    stack.push(2.0f);
    stack.push(3.0f);
    std::cout << stack.pop() << std::endl;
    std::cout << stack.pop() << std::endl;
    std::cout << stack.pop() << std::endl;
    return 0;
}
