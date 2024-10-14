#include <HashMap.hpp>
#include <iostream>


int main() {
    std::cout << "Instantiating" << std::endl;
    HashMap<int, int>* hashMap = new HashMap<int, int>();

    std::cout << "Inserting" << std::endl;
    hashMap->insert(1, 69);

    std::cout << "Looking" << std::endl;
    std::cout << hashMap->lookup(1) << std::endl;
}
