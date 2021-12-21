#include "doubly-linked.h"

List::List(void) {
    first = nullptr;
}

List::~List(void) {
}

void List::insert(int n) {
    Node **pp = &this->first; 
    // check if first is nullptr
    // this means either the list is empty
    // or we arrived to the end

    Node *newNode = new Node; // Allocate new node
    newNode->val = n;  // Assign value
    newNode->next = nullptr; // New node is the last one

    if (*pp == nullptr) {
        newNode->prev = nullptr;
        *pp = newNode;
        return;
    }
    Node *last = *pp;
    while (last->next != nullptr)
        last = last->next;
    // while ( *(&(*pp)->next) != nullptr )
    //     insertR(n, (*(&(*pp)->next);

    last->next = newNode;
    newNode->prev = last; 
    // (*(&(*pp)->next))->next = newNode;
    // newNode->prev = &(*pp)->next;   
}

// void List::insertR(int n, Node **pp){
//     // check if first is nullptr
//     // this means either the list is empty
//     // or we arrived to the end

//     Node *newNode = new Node; // Allocate new node
//     newNode->val = n;  // Assign value
//     newNode->next = nullptr; // New node is the last one

//     if (*pp == nullptr) {
//         newNode->prev = nullptr;
//         *pp = newNode;
//         return;
//     }
//     Node *last = *pp;
//     while (last->next != nullptr)
//         last = last->next;
//     // while ( *(&(*pp)->next) != nullptr )
//     //     insertR(n, (*(&(*pp)->next);

//     last->next = newNode;
//     newNode->prev = last; 
//     // (*(&(*pp)->next))->next = newNode;
//     // newNode->prev = &(*pp)->next;   

// }

void List::reverse(void) {
    Node *next = first;
    Node *last;
    if (next != nullptr) {
        while (next != nullptr) {
            last = next;
            next = next->next;
        }
        
        List newNode;
        while(last != nullptr) {
            newNode.insert(last->val);
            last = last->prev;
        }
        first = newNode.first;
    }
}

void List::print(void) {
    Node *next = first;
    while (next != nullptr) {
        cout << next->val << " ";
        next = next->next;
    }
    cout << endl;
}