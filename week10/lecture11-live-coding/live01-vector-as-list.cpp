// Implementation of a vector clas using linked lists
#include <iostream>
#include "linked-list.h"

using namespace std;

class MyVector {
public:
    // Constructor method
    MyVector(void);
    // Destructor method
    ~MyVector(void);

    // Other useful methods
    unsigned int size(void);
    int at(unsigned int);
    int & operator[](unsigned int);
    void erase(unsigned int);
    void push_back(int);

    // User-defined assignment
    MyVector & operator=(MyVector &);

private:
    // Private members - implementation details, not part of the public API

    // The vector is internally implemented as a linked list
    // The list is represented by a pointer to a node
    Node<int> *first;

    // Some internal methods
    unsigned int sizeR(Node<int> *n) const;
    void deallocate(void);
    void deallocateR(Node<int> *p);
    void eraseR(Node<int> *&p, unsigned int i, unsigned int n);
    void push_backR(int x, Node<int> *&p);
    // void push_backR(int x, Node<int> **p) pointer to pointer
};

// The constructor
MyVector::MyVector(void) {
    // We need to initialize the pointer, otherwise it has an unknown value -> when we create a vector we want to be empty
    first = nullptr ;
    // this->first = nullptr
}

// Destructor method
MyVector::~MyVector(void) {
    // We need to deallocate the linked list
    deallocate();
}

// Deallocate all elements of the vector, recursively
void MyVector::deallocate(){
    deallocateR(first);
    // first Node has been delete in deallocateR, so now is pointing to something that doesn't exist anymore
    // we need to point to nullptr
    first = nullptr;
}

void MyVector::deallocateR(Node<int> *p) {
    if (p == nullptr) {
        return;
    } else {
        deallocateR(p->next);
        delete p;
    }
}

// size() implemented using recursion
unsigned int MyVector::size(void) {
    return sizeR(first);
}

unsigned int MyVector::sizeR(Node<int> *n) const {
    //  we need to count 
    if (n == nullptr) { // base case
        return 0;
    } else {
        return 1 + this->sizeR(n->next);
    }
}

// erase() implemented using recursion
void MyVector::erase(unsigned int n) {
    eraseR(first, 0, n);
}

// Argument 'i' is the current element number, and 'n' is the element to erase
void MyVector::eraseR(Node<int> *&p, unsigned int i, unsigned int n) {
    if (i == n) {
        // We need to remove the current node
        Node<int> *tmp = (*p).next; // Save a pointer to the next node
        delete p;
        p = tmp;
    } else {
        eraseR((*p).next, i+1, n);
    }
}

// push_back() implemented using recursion
void MyVector::push_back(int x) {
    push_backR(x, first);
    // puch_backR(x, &this->first) // we pass the addres of first
}


// ->next give me a pointer, but I want the location where that pointer is stored -> &(*pp)
void MyVector::push_backR(int x, Node<int> *&pp) { // **pp
    // check if first is nullptr
    // this means either the list is empty
    // or we arrived to the end
    if (pp == nullptr){
        // create a new node for x
        Node<int> *newNode = new Node<int>;
        newNode->content = x;
        newNode->next = nullptr;
        // update first to point to the new element
        pp = newNode;
        return;
    }
    
    // otherwise, push back in the rest of the list
    push_backR(x, pp->next); //&((*pp))->next
}

// Method "at" implemented with a loop
// It can of course be implemented with recursion as well
int MyVector::at(unsigned int i) {
    // We check if we are accessing an actual element of the vector
    // otherwise we raise an error
    if (i >= this->size()) {
        throw std::out_of_range("Out-of-range access!");
    }
    
    // We iterate through the list until we find the i-th
    // element or we reach the end of the list
    unsigned int j = 0;
    for (Node<int> *p = first; p != nullptr; p = p->next) {
        if (j == i) {
            return p->content;
        }
        j = j + 1;
    }
    throw std::logic_error("BUG: this line should never be reached!"); // instead of using the return !! -> throw an exception
}

// Here we overload the operator _[_] to access vector elements in array-style
int &MyVector::operator[](unsigned int i) {
    if (i >= this->size()) {
        throw std::out_of_range("Out-of-range access!");
    }
    // note that we do not return an element
    // but a reference to an eledment (see return type)
    unsigned int j = 0;
    for (Node<int> *p = first; p != nullptr; p = p->next) {
        if (j == i) {
            return p->content;
        }
        j = j + 1;
    }
    throw std::logic_error("BUG: this line should never be reached!");
}

// A user-defined assignment operator
MyVector &MyVector::operator=(MyVector &v) {
    // Delete all elements of the internal list in the vector being overwritten
    deallocate();

    // Copy all elements form v's internal list
    for (unsigned int i = 0; i < v.size(); i++) {
        push_back(v[i]);
    }

    return *this;
}

int main(void) {
    // We declare a vector
    MyVector v;

    // We insert some numbers using push_back
    for (unsigned int i = 0; i < 10; i++) {
        v.push_back(i);
    }

    // We access and manipulate some vector elements in array-style
    for (unsigned int i = 2; i < v.size(); i++) {
        v[i] = v[i-1] + v[i-2];
    }

    // We access some elements usint at()
    cout << "Vector after initialization: " << endl;
    for (unsigned int i = 0; i < v.size(); i++) {
        cout << v.at(i) << " ";
    }
    cout << endl;

    MyVector v2;
    // We set b to be equal to a
    v2 = v;
    cout << "Result of assignment v2 = v: " << endl ;
    for (unsigned int i=0; i < v2.size(); i++) {
        cout << v2.at(i) << " ";
    }
    cout << endl;

    cout << "Erasing the 3rd element of v2..." << endl;
    v2.erase(2);
    cout << "Current contents of v2: " << endl ;
    for (unsigned int i=0; i < v2.size(); i++) {
        cout << v2.at(i) << " ";
    }
    cout << endl;

    return 0;
}
