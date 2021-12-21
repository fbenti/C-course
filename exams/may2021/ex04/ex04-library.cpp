#include "ex04-library.h"

// Task 4(a).  Write a placeholder implementation of FilteringBuffer's
//             constructor and methods
FilteringBuffer::FilteringBuffer(int value){
    this->defaultValue = value;
}


// Task 4(b).  Write a working implementation of write() and occupancy()
void FilteringBuffer::write(int v){
    for (int n : this->record) {
        if (n == v)
            return;
    }
    this->buffer.push_back(v);
    this->record.push_back(v);
}

unsigned int FilteringBuffer::occupancy() {
    return this->buffer.size();
}

// Task 4(c).  Write a working implementation of read()
int FilteringBuffer::read(){
    if (this->buffer.size() > 0) {
        int temp = this->buffer.front();
        this->buffer.erase(this->buffer.begin());
        return temp;
    }
    return this->defaultValue;
}

// Task 4(d).  Write a working implementation of reset()
void FilteringBuffer::reset() {
    this->buffer = vector<int> {}; //this->buffer.clear()
    this->record = vector<int> {}; //this->record.clear()
}
// Do not modify
Buffer::~Buffer() {
    // Empty destructor
}