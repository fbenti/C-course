#include <iostream>
#include "ex02-library.h"
using namespace std;

// Task 2(a).  Implement this function
Passenger* find(Passenger *q, unsigned int ticket) {
    if (q == nullptr) {
        return nullptr;
    }
    while(q->next != nullptr) {
        if(q->ticket == ticket)
            return q; 
        q = q->next; 
    }
    return nullptr;
}

// Task 2(b).  Implement this function
Passenger* remove(Passenger *q, unsigned int ticket) {

    Passenger* temp = q;
    Passenger* prev = nullptr;

    // If the ticket searched is the first one
    if (temp != nullptr && temp->ticket == ticket) {
        q = temp->next;
        return q;
    }

    // loop untile the end
    else {
        while (temp != nullptr && temp->ticket != ticket) {
            prev = temp;
            temp = temp->next;
        }
    }

    // not found
    if (temp == nullptr)
        return q;
    
    // otherwise skip the passenger
    prev->next = temp->next;

    return q;
}

// Task 2(c).  Implement this function
Passenger* priority(Passenger *q) {
    Passenger *prior = q;

    if (q == nullptr) {
        return nullptr;
    }
    while(q->next != nullptr) {
        if(q->priority == false)
            prior = remove(prior, q->ticket);
        q = q->next; 
    }
    // check last element
    if (q->priority == false)
        prior = remove(prior, q->ticket);
        
    return prior;
}

// Do not modify
void displayQueue(Passenger *q) {
    if (q == nullptr) {
        return;
    }
    cout << q->name << " - ticket: " << q->ticket;
    if (q->priority) {
        cout << " (priority)";
    }
    cout << endl;
    displayQueue(q->next);
}