#ifndef EX04_LIBRARY_H_
#define EX04_LIBRARY_H_

#include <vector>
using namespace std;

class Buffer {
public:
    virtual void write(int v) = 0;
    virtual int read() = 0;
    virtual unsigned int occupancy() = 0;
    virtual void reset() = 0;
    virtual ~Buffer();
};

// Task 4(a).  Declare the class FilteringBuffer, by extending Buffer
class FilteringBuffer : public Buffer {
public:
    FilteringBuffer(int value);
    void write(int v);
    unsigned int occupancy();
    int read();
    void reset();

private:
    int defaultValue;
    vector<int> buffer;
    vector<int> record;
};

#endif /* EX04_LIBRARY_H_ */
