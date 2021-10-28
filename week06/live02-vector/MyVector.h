#ifndef MYVECTOR_H_
#define MYVECTOR_H_

class MyVector {

public:
    // Constructor methods
    MyVector(void);
    MyVector(int initialCapacity);

    // Destructor method
    ~MyVector(void);

    // Other useful methods
    unsigned int size(void);
    void push_back(int);
    int at(unsigned int);
    int & operator[](unsigned int); // i'm defining how [] work on a object type MyVector
    // There is a difference between 'at' and '[]' in the return type 
    // an integer and a reference to a integer (which means we can use it both as value
    // that we can read a[15] or we can modify it a[15]=20)

    // User-defined assignment
    MyVector & operator=(MyVector &);

private:
    // Private members
    // Used to implement the class, not meant for the user
    int *content;
    unsigned int vsize; //current size (elements contained)
    unsigned int capacity;
    void resize(void);
};

#endif /* MYVECTOR_H_ */