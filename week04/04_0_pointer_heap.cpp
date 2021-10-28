#include <iostream>

using namespace std;

// Create a funciton that return an array --> use HEAP ->> make use of NEW and DELETE

int* makeArray() {
    int *r = new int[2];
    // int r[] = {1,2} --> INCORRECT because the value are assigne in the memory STACK of the functions
    // which will be deleted at the end of the function scope.
    r[0] = 1; r[1]= 2;
    return r;
}

int main()
{
    int *p = makeArray();
    cout << p[0] << endl;
    p[0]++; 
    cout << p[0] << endl;
    delete[] p;
    return 0;
}