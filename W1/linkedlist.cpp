#include <iostream>
#include "LinkedList.h"

int main() {
    LinkedList<int>* linkedList = new LinkedList<int>();

    linkedList->append(1);
    linkedList->append(2);
    linkedList->append(3);

    std::cout << linkedList->head->val << std::endl;
    std::cout << linkedList->head->next->val << std::endl;
    std::cout << linkedList->head->next->next->val << std::endl;
    return 0;
}
