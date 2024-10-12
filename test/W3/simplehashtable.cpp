#include "SimpleHashTable.h"
#include <iostream>

int main() {
  SimpleHashTable<int>* hashTable = new SimpleHashTable<int>();
  hashTable->insert(1);
  hashTable->insert(2);
  hashTable->insert(3);

  for (int i = 0; i < 101; i++) std::cout << hashTable->table[i] << std::endl;
}
