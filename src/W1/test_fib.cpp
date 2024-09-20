#include <iostream>
#include <string>


int fib(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fib(n-2) + fib(n-1);
}

int main() {
    std::string input;
    std::cin >> input;
    int n = atoi(input.c_str());
    std::cout << fib(n) << std::endl;
}
