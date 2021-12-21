#include <iostream>
#include "ex02-library.h"
using namespace std;

// Task 2(a).  Implement this function
Elem* reverse(Elem *list) {
    Elem *prev = nullptr;
    Elem *curr = list;
    Elem * next = nullptr;

    while(curr != nullptr) {
        // Remember the next element to process
        next = curr->next;

        // Make the current element point back to the previous
        curr->next = prev;

        // Move the pointers one element ahead
        prev = curr;
        curr = next;
    }
    // prev now contains the first element of the reversed list
    return prev;
}

// Task 2(b).  Implement this function
Elem* concatenate(Elem *list1, Elem *list2) {
    if (list1 == nullptr) {
        return list2;
    }
    if (list2 == nullptr) {
        return list1;
    }

    Elem *head = list1;
    
    // Go until the end of list1
    while (list1->next != nullptr)
        list1 = list1->next;
    
    // Check if the element are equal
    if (list1->value == list2->value) {
        list1->times += list2->times;
        list1->next = list2->next;
    }
    else {
        list1->next = list2;
    }
    return head;
}

// Task 2(c).  Implement this function
int sum(Elem *list) {
    if (list == nullptr)
        return 0;
    if (list->next == 0)
        return list->value * list->times;
    else {
        return list->value * list->times + sum(list->next); 
    }
}

// Do not modify
void displayRLEList(Elem *list) {
    if (list == nullptr) {
        return;
    }
    cout << " " << list->value << " (x" << list->times << ")";
    displayRLEList(list->next);
}
