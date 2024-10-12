#include "ArrayList.h"
#include <cmath>
#include <iostream>
#include <string>

#define HASH_SIZE 4951

struct CountNode {
    std::string word;
    int count;
    CountNode *next;
    CountNode(std::string word, int count)
        : word(word), count(count), next(nullptr) {};
};

class ChainingCumulativeStringHashTable {
public:
    ChainingCumulativeStringHashTable() {
        for (int i = 0; i < HASH_SIZE; i++) {
            table[i] = nullptr;
        }
    };
    void increment(std::string word, int count) {
        if (lookup(word) != nullptr) {
            CountNode *node = table[hash(word) % HASH_SIZE];
            while (node->word != word) {
                node = node->next;
            }
            node->count += count;
        } else {
            CountNode *node = new CountNode(word, count);
            node->next = table[hash(word) % HASH_SIZE];
            table[hash(word) % HASH_SIZE] = node;
        }
    };
    CountNode *lookup(std::string word) {
        CountNode *node = table[hash(word) % HASH_SIZE];
        while (node != nullptr) {
            if (node->word == word) {
                return node;
            }
            node = node->next;
        }
        return nullptr;
    };
    CountNode *table[HASH_SIZE];
    void print() {
        std::cout << "hash word count" << std::endl;
        for (int i = 0; i < HASH_SIZE; i++) {
            CountNode *node = table[i];
            while (node != nullptr) {
                std::cout << i << " " << node->word << " " << node->count
                          << std::endl;
                node = node->next;
            }
        }
    };
    int hash(std::string word) {
        int result = 0;
        for (size_t i = 0; i < word.length(); ++i) {
            result += word[i] * pow(31, i);
        }
        return result % HASH_SIZE;
    };
    ArrayList<CountNode *> all() {
        ArrayList<CountNode *> all;
        for (int i = 0; i < HASH_SIZE; i++) {
            CountNode *node = table[i];
            while (node != nullptr) {
                all.append(node);
                node = node->next;
            }
        }
        return all;
    };
};
