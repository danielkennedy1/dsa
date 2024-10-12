#include "ChainingHashTable.hpp"
#include <iostream>
#include <string>

int hash(const std::string &element) {
    int result = 0;

    const char *bytePtr = reinterpret_cast<const char *>(&element);
    for (size_t i = 0; i < sizeof(element); ++i) {
        std::cout << "Byte " << i << ": " << static_cast<int>(bytePtr[i])
                  << std::endl;
    }
    return result;
};

int main() {
    ChainingHashTable<std::string> *table =
        new ChainingHashTable<std::string>();

    table->insert("ABCD");
    table->insert("ABCE");
    table->insert("ABCF");
    table->insert("ABCG");

    std::cout << "printout:" << std::endl;
    ArrayList<std::string *> all = table->all();

    for (int i = 0; i < all.length; i++) {
        std::cout << *all.get(i) << std::endl;
    }

    return 0;
}
