#include "ArrayList.h"

int main() {
    ArrayList<int>* array = new ArrayList<int>();

    array->append(1);
    array->append(2);
    array->append(3);
    array->append(4);

    array->get(3) = 12;

    for (int i = 0; i < array->length; i++) std::cout << array->get(i) << ", " << std::endl;
}
