#include <iostream>
#include "linkedlist.h"
using namespace std;

int main() {
    List* list = new LinkedList();
    list->add(10);
    list->add(20);
    list->print();
    delete list;
    return 0;
}