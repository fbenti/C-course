//============================================================================
// Name        : live02-refinement.cpp
// Description : Static method dispatch vs. dynamic method dispatch
//============================================================================

#include <iostream>

using namespace std;

/*
class A {
public:
    void f(); //Original method
};

class B: public A {
public:
    void f(); // Overridden method
};

void main() {
    
    B *b = new B();   ->creating a pointer to a new instance of b, which is the subclass
    A *a = b;   -> define a pointer to class A that points to b, where b is also an instance of A because A is the superclass

    Which f are we invoking now???
    b->f(); -> in this case f() of B
    a->f(); -> remember that a and b point to the same objecte created as an instance of B : invoking f() of A

    -> to avoid this we need to specify when we create classes that we want to use dynamic dispatch,
        so in class A when we define f() as a 'virtual' method
}
*/



class Father {
public:
    void staticMethod(void) { cout << "Calling Father::staticMethod" << endl; };
    virtual void dynMethod(void) { cout << "Calling Father::dynMethod" << endl; };
    virtual ~Father() {}; // See https://www.geeksforgeeks.org/virtual-destructor
};

class Son : public Father {
public:
    void staticMethod(void) { cout << "Calling Son::staticMethod" << endl; };
    void dynMethod(void) { cout << "Calling Son::dynMethod" << endl; };
};

class Nephew : public Son {
public:
    void staticMethod(void) { cout << "Calling Nephew::staticMethod" << endl; };
    void dynMethod(void) { cout << "Calling Nephew::dynMethod" << endl; };
};

void testFatherSon();
void testFatherSonNephew();

int main(void) {
    testFatherSon();
    cout << endl;
    testFatherSonNephew();
    return 0;
}

void testFatherSon() {
    cout << "###############" << endl;
    cout << "Test Father-Son" << endl;
    cout << "###############" << endl;
    Son *s = new Son();
    Father *p = s;

    // Static dispatch of 'staticMethod': based on p’s type
    cout <<"Static dispatch" << endl;
    s->staticMethod();  // calls Son::staticMethod()
    p->staticMethod();  // calls Father::staticMethod()

    // Dynamic dispatch: based on actual type of object pointed by p
    cout << endl << "Dynamic dispatch" << endl;
    s->dynMethod();  // calls Son::dynMethod()
    p->dynMethod();  // calls Son::dynMethod()

    delete s;
}

void testFatherSonNephew() {
    cout << "######################" << endl;
    cout << "Test Father-Son-Nephew" << endl;
    cout << "######################" << endl;
    
    // Creating a pointer to a new instance of Newphew which is a subclass
    Nephew *n = new Nephew();
    Son *s = n;
    // Defining a pointer to a superclass -> this works 
    Father *p = s;

    // Static dispatch of 'staticMethod': based on p’s type
    cout << "Static dispatch" << endl;
    n->staticMethod();  // calls Nephew::staticMethod()
    s->staticMethod();  // calls Son::staticMethod()
    p->staticMethod();  // calls Father::staticMethod()

    // Dynamic dispatch: based on actual type of object pointed by p
    cout << endl << "Dynamic dispatch" << endl;
    n->dynMethod();  // calls Nephew::dynMethod()
    s->dynMethod();  // calls Nephew::dynMethod()
    p->dynMethod();  // calls Nephew::dynMethod()
}
