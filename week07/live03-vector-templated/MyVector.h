#ifndef MYVECTOR_H_
#define MYVECTOR_H_

template<class T>
class MyVector {
public:
    // Constructor methods
    MyVector(void);
    MyVector(int initialCapacity);

    // Destructor method
    ~MyVector(void);

    // Other useful methods
    unsigned int size(void);
    void push_back(T);
    T at(unsigned int);
    T & operator[](unsigned int);

    // User-defined assignment
    MyVector<T> & operator=(MyVector<T> &);

private:
    // Private members
    // Used to implement the class, not meant for the user
    T *content;
    unsigned int vsize;
    unsigned int capacity;
    void resize(void);
};

#include "MyVector.hpp"

#endif /* MYVECTOR_H_ */
