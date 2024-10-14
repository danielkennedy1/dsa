#include "ArrayList.h"
#include <string>

class Trie {
public:
    Trie();
    ~Trie();
    void insert(std::string word);
    void lookup(std::string word);

};
