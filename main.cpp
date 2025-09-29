#include <iostream>
#include "arraylist.h"
using namespace std;

int main() {
    List* list = new ArrayList();
    list->add(5);
    list->add(6);
    list->add(7);
    list->add(5);
    list->add(5);
    list->add(9);
    list->add(5);
    list->add(11);
    list->add(5);
    list->print();
    list->removeAll(5);
    list->print();
    delete list;

    return 0;
}