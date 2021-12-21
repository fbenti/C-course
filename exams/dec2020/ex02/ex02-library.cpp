#include <iostream>
#include "ex02-library.h"
using namespace std;

// Task 2(a).  Implement this function
unsigned int length(Elem *list) {
    if (list == nullptr)
        return 0;
    return list->times + length(list->next);
}

// Task 2(b).  Implement this function
Elem* append(Elem *list, int v) {
    if (list == nullptr){
        Elem *temp = new Elem;
        temp->value = v;
        temp->times = 1;
        temp->next = nullptr;
        list = temp;
        return list;
    }

    // Go until the end
    Elem* head = list;
    while (list->next != nullptr)
        list = list->next;
    // Check if equal
    if (list->value == v) {
        list->times += 1;
    }
    else {
        // Update last element
        Elem *temp = new Elem;
        temp->value = v;
        temp->times = 1;
        temp->next = nullptr;
        list->next = temp;
    }
    return head;
}

// Task 2(c).  Implement this function
Elem* buildRLEList(int *data, unsigned int n) {
    Elem *newList = nullptr;
    for (int i = 0; i < n; i++) {
        newList = append(newList, data[i]);
    }
    return newList;
}

// Do not modify
void displayRLEList(Elem *list) {
    if (list == nullptr) {
        return;
    }
    cout << " " << list->value << " (x" << list->times << ")";
    displayRLEList(list->next);
}
