#include <iostream>
#include "Stack.h"

int main() {
    Stack<float> stack = Stack<float>();
    stack.push(1.0f);
    stack.push(2.0f);
    stack.push(3.0f);
    std::cout << stack.pop() << std::endl;
    std::cout << stack.pop() << std::endl;
    std::cout << stack.pop() << std::endl;
    return 0;
}
