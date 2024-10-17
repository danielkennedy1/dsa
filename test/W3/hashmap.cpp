#include <HashMap.hpp>
#include <iostream>

void printTable(HashMap<int, int>* hashMap) {
    for (int i = 0; i < hashMap->size; i++) {
        std::cout << "Index: " << i << " ";
        MapNode<int, int>* node = hashMap->table[i];
        if (node != nullptr) {
            std::cout << "Key: " << node->key << " Value: " << node->value;

            while (node->next != nullptr) {
                node = node->next;
                std::cout << " -> Key: " << node->key << " Value: " << node->value;
            }


            std::cout << std::endl;

        } else {
            std::cout << "NULL" << std::endl;
        }
    }
    std::cout << std::endl;
}

int main() {
    HashMap<int, int>* hashMap = new HashMap<int, int>();

    hashMap->put(1, 1);
    hashMap->put(2, 2);
    hashMap->put(3, 3);
    hashMap->put(4, 4);
    hashMap->put(5, 5);

    hashMap->remove(3);
    
    printTable(hashMap);

    int v;
    bool success = hashMap->lookup(3, v);

    if (success) {
        std::cout << "found: " << v << std::endl;
    } else {
        std::cout << "not found" << std::endl;
    }

    std::cout << "Size: " << hashMap->size << std::endl;
}
