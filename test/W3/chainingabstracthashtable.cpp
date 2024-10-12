#include <string>
#include <iostream>
#include "ArrayList.h"
#include "ChainingAbstractHashTable.hpp"
#include <cmath>

struct WordCount {
  std::string word;
  int count;
  WordCount(std::string word, int count) : word(word), count(count) {};
};

int main() {

  ArrayList<std::string>* cat_dog = new ArrayList<std::string>();
  cat_dog->append("the");
  cat_dog->append("dog");
  cat_dog->append("and");
  cat_dog->append("the");
  cat_dog->append("cat");
  cat_dog->append("and");
  cat_dog->append("the");
  cat_dog->append("dog");

  ChainingAbstractHashTable<WordCount> *table = new ChainingAbstractHashTable<WordCount>(
    [](WordCount wc) -> int {
      int result = 0;
      for (size_t i = 0; i < wc.word.length(); ++i) {
        result += wc.word[i] * pow(31, i);
      }
      return result;
    },
    [](WordCount wc1, WordCount wc2) -> bool {
      return wc1.word == wc2.word;
    },
    [](WordCount wc) -> std::string {
      return wc.word + " " + std::to_string(wc.count);
    }
  );

  for (int i = 0; i < cat_dog->length; i++) {
    std::string word = cat_dog->get(i);
    WordCount wc(word, 1);
    WordCount *wc2 = table->lookup(wc);
    if (wc2 == nullptr) {
      table->insert(wc);
    } 
    else {
      wc2->count += 1;
    }
  }

  std::cout << "printout:" << std::endl;
  table->print();


}
