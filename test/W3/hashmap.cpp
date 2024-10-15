#include <HashMap.hpp>
#include <iostream>


int main() {
    HashMap<const char*, int>* hashMap = new HashMap<const char*, int>();

    std::string key = "a123";

    hashMap->put(key.c_str(), 22340017);

    int v;
    hashMap->lookup(key.c_str(), v); 

    std::cout << v << std::endl;
}
