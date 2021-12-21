#include "ex04-library.h"

// Task 4(a).  Write a placeholder implementation of LimitedBuffer's
//             constructor and methods

LimitedBuffer::LimitedBuffer(unsigned int capacity, int value) {
    this->capacity = capacity;
    this->default_value = value;
}

void LimitedBuffer::write(int v) {
    if (this->buffer.size() < this->capacity) 
        this->buffer.push_back(v);
}

unsigned int LimitedBuffer::occupancy() {
    return this->buffer.size();
}


// Task 4(b).  Write a working implementation of write() and occupancy()


// Task 4(c).  Write a working implementation of read()

int LimitedBuffer::read(){
    if (this->buffer.empty())
        return this->default_value;
    int temp = this->buffer.front();
    // int temp = this->buffer[0];
    this->buffer.erase(this->buffer.begin());
    return temp;
}

// Do not modify
Buffer::~Buffer() {
    // Empty destructor
}
