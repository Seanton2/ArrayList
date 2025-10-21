#include <iostream>
#include "arraylist.h"
using namespace std;

int main() {
    ArrayList* List = new ArrayList();
    
    List->add(10);
    List->add(20);
    List->print();
    delete List;
    return 0;
}