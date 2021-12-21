#include "ex04-library.h"

// Task 4(a).  Write a placeholder implementation of SensorBuffer's
//             constructor and methods
SensorBuffer::SensorBuffer(unsigned int n) {
    this->avgElem = n;
}

// Task 4(b).  Write a working implementation of write() and writeCount()
void SensorBuffer::write(int v) {
    this->buffer.push_back(v);
}

unsigned int SensorBuffer::writeCount() {
    return this->buffer.size();
}

// Task 4(c).  Write a working implementation of read()
int SensorBuffer::read(){
    if (this->buffer.size() > 0)
        return this->buffer.back();
    return 0;
}

// Task 4(d).  Write a working implementation of readAvg()
int SensorBuffer::readAvg() {
    if (this->buffer.size() == 0)
        return 0;
    if (this->buffer.size() < this->avgElem) {
        int count = 0;
        for (int i = 0; i < buffer.size(); i++) {
            count += buffer[i];
        }
        return count / buffer.size();
    }
    vector<int> y(buffer.end() - avgElem, buffer.end());
    int count = 0;
    for (int i = 0; i < avgElem; i++) {
        count += y[i];
    }
    return count / avgElem;
}

// Do not modify
Buffer::~Buffer() {
    // Empty destructor
}
