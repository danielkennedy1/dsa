#include "LinkedList.h"
#include <iostream>

void printList(LinkedList<int> *list) {
  std::cout << "list: ";
  for (int i = 0; i < list->length; i++)
    std::cout << list->get(i) << ", ";
  std::cout << "length: " << list->length;
  std::cout << std::endl;
}

int main() {
  std::cout << "LINKED LIST" << std::endl;
  LinkedList<int> *linkedList = new LinkedList<int>();

  std::cout << "Appending 1, 2, 3 to list" << std::endl;
  linkedList->append(1);
  linkedList->append(2);
  linkedList->append(3);

  printList(linkedList);

  std::cout << "Removing element at index 2: " << std::endl;
  linkedList->remove(2);

  printList(linkedList);

  std::cout << "Removing element at index 0: " << std::endl;
  linkedList->remove(0);

  printList(linkedList);

  std::cout << "Inserting value 20 at index 0" << std::endl;
  linkedList->insert(20, 0);

  printList(linkedList);

  std::cout << "Clearing list" << std::endl;
  linkedList->clear();

  printList(linkedList);

  return 0;
}
