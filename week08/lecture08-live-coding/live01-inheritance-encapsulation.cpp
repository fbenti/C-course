//============================================================================
// Name        : live01-inheritance-encapsulation.cpp
// Description : Encapsulation of superclass members and inheritance
//============================================================================

// PRIVATE : members accessible by objects of the class and no one else

// PROTECTED: members are accessible by objects of the class and derived classes

// PUBLIC: members are accessible by everyone

class A {
public:
    int x; // accessible to everyone
    int getz(); // accessible to everyone
protected:
    int y; // accessible to all derived classes (A, B, C, D)
private:
    int z; // accessible only to A
};

/*
class B : A {..}
-> B inherits all public and protected member variables
-> B does not inherit private metods of A
-> B cannot access the private member varibles of A

class B: public A{..}
    everything that is public in A remains public in B
    B inherits protected members which remain protected members

class B:  protected A{..} 
    B inherits public members, which become protected
    B inherits protected members which remain protected

class B: private A{..}
    B inherits public members, which become private
    B inherits protected member which become private
*/

class B : public A {
    // x is public
    // getz() is public
    // y is protected -> but now I can access it!!!
    // z is not accessible from B
public:
    int gety();
};

class C : protected A { // we cannot access anymore the public method in A, so getz is not accessible
    // x is protected
    // getz() is protected
    // y is protected
    // z is not accessible from C
public:
    int gety();
};

class D : private A {
    // x is private
    // getz() is private
    // y is private
    // z is not accessible from D
public:
    int gety();
};

int A::getz() {
    return z;
};

int B::gety() {
    return y;
}

int C::gety() {
    return y;
}

int D::gety() {
    return y;
}

int main() {
    A a;
    a.x = 0;
    // a.y = 0; // Does not compile

    B b;
    b.x = 0;
    b.getz();

    C c;
    // c.x = 0; // Does not compile
    // c.getz(); // Does not compile

    D d;
    // d.x = 0; // Does not compile
    // d.getz(); // Does not compile

    return 0;
}