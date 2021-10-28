// Swapping two variables
#include <iostream>
using namespace std;

// This "swap" does not work, because the values of the variables are copied
// when swapWrong() is called
void swapWrong(int x, int y) {
    int tmp = x;
    x = y;
    y = tmp;
}

// This swap works, because it swaps the values stored at the given memory
// addresses
void swap(int *x, int *y) {
    int tmp = *x;
    cout << tmp << endl;
    *x = *y;
    *y = tmp;
}

// This swap also works, because it swaps the values of the given references
// (which work like pointers, but with let you omit * and &)
void swapRef(int &x, int &y) { // x and y are references to some integer: a reference is a pointer
    int tmp = x; // we are working on aliases of variables that are passed
    x = y;
    y = tmp;
}

int main() {
    int a = 1, b = 42;

    cout << "a=" << a << ", b=" << b << endl; // We get a=1, b=42

    swapWrong(a, b);
    cout << "After swapWrong(): ";
    cout << "a=" << a << ", b=" << b << endl; // We still get a=1, b=42

    cout << &a << endl;
    cout << a << endl;

    swap(&a, &b);
    cout << "After swap(): ";
    cout << "a=" << a << ", b=" << b << endl; // We now get a=42, b=1

    swapRef(a, b);
    cout << "After swapRef(): ";
    cout << "a=" << a << ", b=" << b << endl; // We now get a=1, b=42

    return 0;
}