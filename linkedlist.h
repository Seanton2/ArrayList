#include <iostream>
#include "list.h"
#include "node.h"
using namespace std;

class LinkedList : public List {
    node* head;
    node* tail;
    int size; // index

    public:
        LinkedList() {
            head = nullptr;
            tail = nullptr;
            size = 0;
        }

        // STEPS
        // 1. Start from the head node
        // 2. While the current node is not null
        //    a. Store the next node
        //    b. Free the current node
        //    c. Move to the next node
        // 3. Repeat until all nodes are freed
        ~LinkedList() {
            node* current = head;
            while(current) { // current != null
                node* next_node = current->next;
                free(current);
                current = next_node;
            }
        }

        // STEPS
        // 1. Create a new node, and check if it was created successfully
        // 2. Assign the value to the new node
        // 3. If the list is empty
        //   a. Set head to the new_node
        // 4. If the list is not empty
        //   a. Set tail's next to the new_node
        // 5. Update tail to the new node
        // 6. Increment size
        void add(int num) {
            node* new_node = (node*) calloc(1, sizeof(node));

            if(!new_node) return; // new_node == null, memory allocation failed
            new_node->elem = num;

            if(!head) { // head == null
                head = new_node;
            } else {
                tail->next = new_node;
            }
            tail = new_node;
            size++;
        }

        // STEPS
        // 1. Start from the head node
        //    a. Initialize a pointer for the previous node (null at start)
        //    b. Initialize a counter for the position (1-based index)
        // 2. While the current node is not null
        //    a. If the current node's element matches the target number
        //       i. If the current node is the head, update head to the next node
        //       ii. If the current node is not the head, link the previous' next to the current's next node
        //       iii. If the current node is the tail, update tail to the previous node
        //       iv. Free the current node
        //       v. Decrement size and return the position (1-based index)
        //    b. Move to the next node, keeping track of the previous node and position
        // 3. If the number is not found, return -1 (indicating not found)
        int remove(int num) { // remove(20);
            node* current = head;
            node* prev = nullptr;
            int ctr = 1;
            while(current) {
                if(current->elem == num) {
                    if(current == head) {
                        head = head->next;
                    } else {
                        prev->next = current->next;
                    }

                    if(current == tail) {
                        tail = prev;
                    }

                    free(current);
                    size--;
                    return ctr;
                }
                prev = current;
                current = current->next;
                ctr++;
            }
            return -1;
        }

        // STEPS
        // 1. Start from the head node
        // 2. While the current node is not null
        //    a. Print the current node's element
        //    b. Move to the next node
        // 3. Print a newline at the end
        void print() {
            node* current = head;
            while(current) { // current != null
                cout << current->elem;
                if (current->next) cout << " -> ";
                current = current->next;
            }
            cout << endl;
        }
};