#include <HashMap.hpp>
#include <iostream>


void printTable(HashMap<int, int>* hashMap) {
    for (int i = 0; i < hashMap->size; i++) {
        std::cout << "Index: " << i << " ";
        if (hashMap->table[i] != nullptr) {
            std::cout << hashMap->table[i]->key << std::endl;
        } else {
            std::cout << "NULL" << std::endl;
        }
    }
    std::cout << std::endl;
}

int main() {
    HashMap<int, int>* hashMap = new HashMap<int, int>();


    hashMap->put(1, 1);
    printTable(hashMap);
    hashMap->put(2, 2);
    printTable(hashMap);
    hashMap->put(3, 3);
    printTable(hashMap);
    hashMap->put(4, 4);
    printTable(hashMap);
    hashMap->put(5, 5);
    printTable(hashMap);

    int v;
    hashMap->lookup(5, v); 

    for (int i = 1; i < 6; i++) {
        hashMap->lookup(i, v);
        std::cout << v << std::endl;
    }

    std::cout << "Size: " << hashMap->size << std::endl;
}
