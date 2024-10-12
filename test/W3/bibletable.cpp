#include "ChainingCumulativeStringHashTable.hpp"
#include <string>
#include <fstream>

int main() {
  ChainingCumulativeStringHashTable* table = new ChainingCumulativeStringHashTable();

  std::ifstream file("bible.txt");

  std::string word;
  while (file >> word) {
    table->increment(word, 1);
  }

  table->print();


}
