//============================================================================
// Name        : live03-constructors.cpp
// Description : Constructors and inheritance
//============================================================================

#include <iostream>

using namespace std;

// How constructrs behave with inheritance?? -> CONSTRUCTORS are not inheritated by subclass

class Father {
public:
    Father(); // default constructor
    Father(int u, int v); // initialize some internal fields, x which is protected and y which is private
    // so to initialize y (private) the only method is to call the constructor
    virtual void display(void);
    virtual ~Father() {}; // See https://www.geeksforgeeks.org/virtual-destructor
protected:
    int x;
private:
    int y;
};

class Son : public Father {
public:
    // we may want to initialize x and y in the father, plus new method introduced (z which is private)
    // but we cannot give a meaningful value to y because it was private in father, so inaccessible in son.
    // --->>> 
    Son(int u, int v);
    void display(void);
private:
    int z;
};

Father::Father() {
    this->x = 101;
    this->y = 101;
}

Father::Father(int u, int v) {
    this->x = u;
    this->y = v;
}

// Note that Son's constructor needs to invoke Father's constructor, if Son
// wants to initialize the private variable y in Father (that Son cannot access)
Son::Son(int u, int v) : Father(u, 42) { // specifically call one of the constructor of father
    // this->x = u; // Redundant, because Father's constructor initialises x
    this->z = v;
}

void Father::display(void) {
    cout << "x=" << x << ", y=" << y << endl;
}

void Son::display(void) {
    cout << "x=" << x << ", z=" << z << endl;
}

int main(void) {
    Father f(10, 10);
    Son s(20, 20);

    cout << "Father: ";
    f.display();

    cout << "Son: ";
    s.display();

    // we are overwriting an instance of father with an instance of son ->  it's valid becuase
    // everytime we need an instance of a superclass we can us a subclass.
    
    // so what happen if we don't use the modify constructor, is that a instance of father with 
    //the default constructor is created (101,101)and the overwrite with son
    // What we want, is that when we create a son object we also want to assign some specific value
    // to the private field of father (not the default one) -> explicity call one of the father
    // constructor when creating instances of subclasses ( if we don't specify anything, then the
    // default constructor of Father is called inside Son)
    f = s; 

    cout << "Father (after the assignment f = s): ";
    f.display();

    return 0;
}
