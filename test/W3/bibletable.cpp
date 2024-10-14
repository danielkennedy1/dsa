#include "ArrayList.h"
#include "ChainingHashTable.hpp"
#include <fstream>
#include <string>

int main() {
    ChainingHashTable<std::string> *table =
        new ChainingHashTable<std::string>();

    std::cout << "reading file" << std::endl;
    std::ifstream file("bible.txt");


    std::cout << "inserting" << std::endl;
    int i = 0;
    std::string word;
    while (file >> word) {
        table->insert(word);
    }

    std::cout << "printout:" << std::endl;
    ArrayList<std::string *> all = table->all();

    std::cout << "length of all: " << all.length << std::endl;



    //for (int i = 0; i < all.length; i++) {
    //    std::cout << "hash: " << table->hash(*all.get(i)) << " value: " << *all.get(i) << std::endl;
    //}


}
