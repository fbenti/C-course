// Example of templated class
// Example based on pairs: see http://www.cplusplus.com/reference/utility/pair/
#include <iostream>
#include <vector>

using namespace std;

template <class A, class B>
class MyPair {
private:
    A a;
    B b;

public:
    MyPair();
    MyPair(A a, B b);
    A first(void);
    B second(void);
    MyPair<B,A> flip(void);
    MyPair<A,B> & operator=(MyPair<A,B> & p);
    void display(void);
};

template <class A, class B>
MyPair<A,B>::MyPair() {
    // Default constructor, leaves the pair uninitialised
}

template <class A, class B>
MyPair<A,B>::MyPair(A a, B b) {
    this->a = a;
    this->b = b;
}

template <class A, class B>
A MyPair<A,B>::first(void) {
    return this->a;
}

template <class A, class B>
B MyPair<A,B>::second(void) {
    return this->b;
}

template <class A, class B>
MyPair<B,A> MyPair<A,B>::flip(void) {
    MyPair<B,A> p(b,a);
    return p;
}

template <class A, class B>
MyPair<A,B> & MyPair<A,B>::operator=(MyPair<A,B> & p){
    this->a = p.first();
    this->b = p.second();
    return *this;
}

template <class A, class B>
void MyPair<A,B>::display(void){
    cout << "<" << this->a << "," << this->b << ">" << endl;
}

// Some templated functions for pairs

// Test if the second element of p matches the first element of q
template <class A, class B, class C>
bool match(MyPair<A,B> p, MyPair<B,C> q) {
    return (p.second() == q.first());
}

// Join a pair by taking the first component of the first pair
// and the second component of the second pair
template <class A, class B, class C>
MyPair<A,C> join(MyPair<A,B> p, MyPair<B,C> q) {
    MyPair<A,C> r(p.first(), q.second());
    return r;
}

int main(void) {
    MyPair<string, int> a("Alice", 1);
    MyPair<string, int> b("Bob", 2);

    MyPair<int, int> likes(1, 2);

    // We can also have pairs of pairs!
    MyPair<MyPair<string, int>, double> test(a, 3.14);

    a.display();
    b.display();

    likes.display();

    if (match<string, int, int>(a, likes)
            && match<int, int, string>(likes, b.flip())) {
        MyPair<string, string> gossip = join<string, int, string>(a, b.flip());
        cout << "Gossip alert: ";
        gossip.display();
    }

    return 0;
}



