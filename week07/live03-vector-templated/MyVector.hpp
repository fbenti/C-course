#include "MyVector.h"

#include <iostream>

// The constructor
template<class T>
MyVector<T>::MyVector(void) {
    // We decide here to start with a small capacity
    this->capacity = 1;
    this->vsize = 0;
    // We allocate the space we need dynamically
    this->content = new T[capacity];
    return;
}

// The constructor
template<class T>
MyVector<T>::MyVector(int initialCapacity) {
    // We decide here to start with a small capacity
    capacity = initialCapacity;
    vsize = 0;
    // We allocate the space we need dynamically
    content = new T[capacity];
    return;
}

// Destructor method
template<class T>
MyVector<T>::~MyVector(void) {
    // We need to deallocate the array
    delete [] content;
    return;
}

template<class T>
void MyVector<T>::resize() {
    // Save pointer to current array
    T *old_content = content;

    // Allocate new array: we try to double the current capacity
    capacity = capacity * 2;
    content = new T[capacity];

    // Copy content
    for (unsigned int i = 0; i < vsize; i++) {
        content[i] = old_content[i];
    }

    // Delete old array
    delete[] old_content;
}

template<class T>
unsigned int MyVector<T>::size(void) {
    return vsize;
}

template<class T>
void MyVector<T>::push_back(T x) {
    // Resize array if full
    if (vsize == capacity) {
        resize();
    }

    // Insert new element
    content[vsize] = x;
    vsize = vsize + 1;

}

template<class T>
T MyVector<T>::at(unsigned int i) {
    // If we are accessing outside the last element, we raise an error
    if (i >= vsize){
        throw std::out_of_range("Access out of range");
    }
    return content[i];
}

// Here we overload the operator [_] to access MyVector elements in array-style
template<class T>
T & MyVector<T>::operator[](unsigned int i) {
    if (i>=vsize) {
        throw std::out_of_range("Access out of range");
    }
    // Note that we do not return an element but a reference to an element (see return type)
    return content[i];
}

// Our custom assignment operator, needed to handle dynamic allocations
template<class T>
MyVector<T> & MyVector<T>::operator=(MyVector &v) {
    // The next 3 lines show what the default assignment operator = would do
    this->capacity = v.capacity;
    this->vsize = v.vsize;
    // this->content = v.content; // Would be wrong: would just copy the pointer

    // Instead of copying a pointer, we want to deallocate our old contents...
    delete[] this->content;
    // ...allocate an array matching our capacity (which is also v's capacity)...
    this->content = new T[this->capacity];
    // ...and copy the contents of v
    for (unsigned int i=0; i < vsize; i++) {
        this->content[i] = v.content[i];
    }
    return *this;
}

