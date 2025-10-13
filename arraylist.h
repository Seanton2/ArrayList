#include <iostream>
#include "list.h"
#define INITIAL_CAPACITY 5
#define GROWTH_FACTOR 1.5
using namespace std;

class ArrayList : public List {
    int* array;
    int index;
    int capacity = INITIAL_CAPACITY;

    void dynamic_expand() {
        int new_size = ceil(capacity * GROWTH_FACTOR);
        int* new_array = (int*) realloc(array, new_size * sizeof(int));
        if(new_array) {
            array = new_array;
            capacity = new_size;
        }
    }

    void dynamic_shrink() {
        if(capacity == INITIAL_CAPACITY) return;
        int new_size = ceil(capacity * 0.75);
        if(new_size < INITIAL_CAPACITY) new_size = INITIAL_CAPACITY;
        int* new_array = (int*) realloc(array, new_size * sizeof(int));
        if(new_array) {
            array = new_array;
            capacity = new_size;
        }
    }

    public:
        ArrayList() {
            array = (int*) malloc(INITIAL_CAPACITY * sizeof(int));
            index = 0;
        }

        ~ArrayList() {
            free(array);
        }
        
        void add(int num) {
            if(index == capacity) dynamic_expand();
            array[index++] = num;
        }

        int removeAt(int pos) {
            if(pos < 1 || pos > index + 1) return -1;
            int removed = array[pos-1];
            remove(removed);
            return removed;
        }

        void addAt(int num, int pos) {
            if(pos < 1 || pos > index + 1) return;
            if(index == capacity) dynamic_expand();
            for(int i=index; i>=pos; i--) {
                array[i] = array[i-1];
            }
            array[pos-1] = num;
            index++;
        };

        int get(int pos) {
            if(pos < 1 || pos > index + 1) return -1;
            return array[pos-1];
        };

        int size() {
            return index;
        };

        bool isEmpty() {
            return index == 0;
        };

        int remove(int num) {
            int pos = -1;

            for(int i=0; i<index; i++) {
                if(array[i] == num) {
                    pos = i;
                    break;
                }
            }

            if(pos == -1) return pos;

            for(int i=pos; i<index-1; i++) {
                array[i] = array[i+1];
            }
            index--;

            if(index < 2.0/3 * capacity) {
                dynamic_shrink();
            }

            return pos + 1;
        };

        void removeAll(int num) {
            int i = 0;
            while(i < index) {
                if(array[i] == num) {
                    remove(num);
                } else {
                    i++;
                }
            }
        }

        void print() {
            if(isEmpty()) {
                cout << "List is empty." << endl;
                return;
            }
            for(int i = 0; i < index; i++) {
                cout << array[i] << " ";
            }
            for (int i = index; i < capacity; i++) {
                cout << "? ";
            }
            cout << endl;
        };
};