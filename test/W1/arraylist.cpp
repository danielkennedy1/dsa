#include "ArrayList.h"
#include <iostream>

void printList(ArrayList<int> *list) {
    std::cout << "list: ";
    for (int i = 0; i < list->length; i++)
        std::cout << list->get(i) << ", ";
    std::cout << "length: " << list->length << ", ";
    std::cout << "size: " << list->size << ", ";
    std::cout << std::endl;
}

int main() {
    std::cout << "ARRAY LIST" << std::endl;

    ArrayList<int> *arrayList = new ArrayList<int>();

    std::cout << "Appending 1, 2 to list" << std::endl;
    arrayList->append(1);
    arrayList->append(2);

    printList(arrayList);

    std::cout << "Appending 3 to list" << std::endl;
    arrayList->append(3);

    printList(arrayList);

    std::cout << "Removing element at index 2: " << std::endl;
    arrayList->remove(2);

    printList(arrayList);

    std::cout << "Removing element at index 0: " << std::endl;
    arrayList->remove(0);

    printList(arrayList);

    std::cout << "Inserting value 20 at index 0" << std::endl;
    arrayList->insert(20, 0);

    printList(arrayList);

    std::cout << "Clearing list" << std::endl;
    arrayList->clear();

    printList(arrayList);

    return 0;
}
