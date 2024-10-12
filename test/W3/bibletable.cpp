#include "ArrayList.h"
#include "ChainingHashTable.hpp"
#include <fstream>
#include <string>

int main() {
    ChainingHashTable<std::string> *table =
        new ChainingHashTable<std::string>();

    std::ifstream file("bible.txt");

    std::string word;
    while (file >> word) {
        table->insert(word);
    }

    std::cout << "printout:" << std::endl;
    ArrayList<std::string *> all = table->all();

    for (int i = 0; i < all.length; i++) {
        std::cout << *all.get(i) << std::endl;
    }
}
