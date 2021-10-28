#include "MyVector.h"

#include <iostream>

// if we have a pointer to a class/structure we use the arrow ->
// if we have a pointer to an istance we use the the dot .

// The constructor
MyVector::MyVector(void) {
    // We decide here to start with a small capacity
    capacity = 1;
    vsize = 0;
    // We allocate the space we need dynamically
    content = new int[capacity];
    return;
}

// The constructor
MyVector::MyVector(int initialCapacity) {
    // We decide here to start with a small capacity
    capacity = initialCapacity;
    vsize = 0;
    // We allocate the space we need dynamically: it's need to be deleted in the DECONSTRUCT
    content = new int[capacity]; // we are initialing the content to a dinamic size array
    // we need to use delete[] because when MyVector is deallocated, the memory
    // used will not be freed, 'new' will not be automatically destroyed.
    return;
}

// Destructor method
MyVector::~MyVector(void) {
    // We need to deallocate the array
    // everything allocated with NEW should be created here.
    delete [] content;
    return;
}

void MyVector::resize() {
    // Save pointer to current array
    int *old_content = content;

    // Allocate new array: we try to double the current capacity
    capacity = capacity * 2;
    content = new int[capacity];

    // Copy content
    for (unsigned int i = 0; i < vsize; i++) {
        content[i] = old_content[i];
    }

    // Delete old array
    delete [] old_content;
}

unsigned int MyVector::size(void) {
    return vsize;
}

void MyVector::push_back(int x) {
    // Resize array if full
    //  we can write everything with this->
    if (vsize == capacity) {
        resize();
    }
    // Insert new element
    content[vsize] = x;
    vsize++;

}

int MyVector::at(unsigned int i) {
    // If we are accessing outside the last element, we raise an error
    if (i >= vsize){
        throw std::out_of_range("Access out of range");
    }
    return content[i];
}

// Here we overload the operator [_] to access MyVector elements in array-style
int & MyVector::operator[](unsigned int i) {
    if (i>=vsize) {
        throw std::out_of_range("Access out of range");
    }
    // Note that we do not return an element but a reference to an element (see return type)
    return content[i];
}

// Our custom assignment operator, needed to handle dynamic allocations
MyVector & MyVector::operator=(MyVector &v) {
    // The next 3 lines show what the default assignment operator = would do
    this->capacity = v.capacity;
    this->vsize = v.vsize;
    // this->content = v.content; // Would be wrong: would just copy the pointer

    // Instead of copying a pointer, we want to deallocate our old contents...
    // when the method assignment = is called, b is already constructed, so this->content is
    // is already initialized and point to an array -> we need to delete it before copying
    delete[] this->content;
    // ...allocate an array matching our capacity (which is also v's capacity)...
    this->content = new int[this->capacity];
    // ...and copy the contents of v
    for (unsigned int i=0; i < vsize; i++) {
        this->content[i] = v.content[i];
    }
    return * this;
}