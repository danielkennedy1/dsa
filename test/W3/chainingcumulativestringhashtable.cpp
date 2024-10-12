#include "ChainingCumulativeStringHashTable.hpp"
#include <string>
#include "ArrayList.h"
#include <iostream>
#include <stdlib.h>

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

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

  ArrayList<std::string>* cow_pony = new ArrayList<std::string>();
  cow_pony->append("the");
  cow_pony->append("pony");
  cow_pony->append("and");
  cow_pony->append("the");
  cow_pony->append("cow");
  cow_pony->append("and");
  cow_pony->append("the");
  cow_pony->append("pony");


  ChainingCumulativeStringHashTable* cat_dog_table = new ChainingCumulativeStringHashTable();
  for (int i = 0; i < cat_dog->length; i++) {
    std::string word = cat_dog->get(i);
    cat_dog_table->increment(word, 1);
  }

  ChainingCumulativeStringHashTable* cow_pony_table = new ChainingCumulativeStringHashTable();
  for (int i = 0; i < cow_pony->length; i++) {
    std::string word = cow_pony->get(i);
    cow_pony_table->increment(word, 1);
  }

  std::cout << BOLDCYAN << "cat_dog_table" << RESET << std::endl;
  cat_dog_table->print();
  std::cout << BOLDCYAN << "cow_pony_table" << RESET << std::endl;
  cow_pony_table->print();

  ChainingCumulativeStringHashTable* combined_table = cat_dog_table;

  ArrayList<CountNode*> cow_pony_all = cow_pony_table->all();
  for (int i = 0; i < cow_pony_all.length; i++) {
    CountNode* node = cow_pony_all.get(i);
    combined_table->increment(node->word, node->count);
  }

  std::cout << BOLDCYAN << "combined_table" << RESET << std::endl;
  combined_table->print();

  return 0;

}
