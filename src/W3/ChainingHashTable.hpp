#include "ArrayList.h"
#include <string>
#include <iostream>

#define HASH_SIZE 4951

template <typename T> struct ChainNode {
  T element;
  ChainNode *next = nullptr;
  ChainNode<T>(T element) : element(element) {};
};

template <typename T> class ChainingHashTable {
public:

  ChainingHashTable(int(*hash)(T), bool(*equals)(T, T), std::string(*toString)(T)) : hash(hash), equals(equals), toString(toString) {
    // Produces some interesting errors when you don't zero the memory
    for (int i = 0; i < HASH_SIZE; i++) {
      table[i] = nullptr;
    }
  };

  ChainNode<T> *table[HASH_SIZE];
  int (*hash)(T);
  bool (*equals)(T, T);
  std::string (*toString)(T);

  void insert(T element){
    if (lookup(element) == nullptr) {
      ChainNode<T> *node = new ChainNode<T>(element);
      table[hash(element) % HASH_SIZE] = node;
    } else {
      ChainNode<T> *node = table[hash(element) % HASH_SIZE];
      while (node->next != nullptr) {
        node = node->next;
      }
      ChainNode<T> *newNode = new ChainNode<T>(element);
      newNode->element = element;
      node->next = newNode;
    }
  };
  
  T* lookup(T element) {
    ChainNode<T> *node = table[hash(element) % HASH_SIZE];
    while (node != nullptr) {
      if (equals(node->element, element)) {
        return &node->element;
      }
      node = node->next;
    }
    return nullptr;
  };

  void print() {
    std::cout << "hash word count" << std::endl;
    for (int i = 0; i < HASH_SIZE; i++) {
      ChainNode<T>* node = table[i];
      while (node != nullptr) {
        std::cout << i << " " << toString(node->element)<< std::endl;
        node = node->next;
      }
    }
  };

  ArrayList<T*> all() {
    ArrayList<T*> all;
    for (int i = 0; i < HASH_SIZE; i++) {
      ChainNode<T> *node = table[i];
      while (node != nullptr) {
        all.append(node->element);
        node = node->next;
      }
    }
    return all;
  };
};
