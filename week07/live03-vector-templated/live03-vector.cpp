//============================================================================
// Name        : live03-vector.cpp
// Description : My own vector implementation, using templates
//============================================================================

#include <iostream>
#include "MyVector.h"

using namespace std;

int main(void){
    // We declare a MyVector a
    MyVector<double> a;

    cout << "The initial size is: " <<  a.size() << endl;

    // We insert some numbers with push_back
    for (unsigned int i=0; i < 10; i++) {
        a.push_back(i + 0.1);
    }
    cout << "After the insertions the size is: " <<  a.size() << endl;

    cout <<"[] "<< a[7] << endl;
    cout <<"at "<< a.at(7) << endl;

    cout << "We access elements in array-style or using 'at': " << endl;
    for(unsigned int i = 0; i < a.size(); i++){
            cout << a.at(i) << " " << a.at(i) << endl;
    }
    cout << endl;

    // We open a new scope
    {
        MyVector<double> b;
        // We set b to be equal to a
        b = a;
        cout << "We 'copied' the vector: " << endl;
        for (unsigned int i = 0; i < b.size(); i++){
            cout << b[i] << " ";
        }
        cout << endl;

        cout << "We access and manipulate b's elements..." << endl;
        for (unsigned int i = 2; i < a.size(); i++){
                b[i] = b[i-1] + b[i-2];
        }
        cout << "The vector b now contains: " << endl;
        for (unsigned int i = 0; i < b.size(); i++) {
            cout << b[i] << " ";
        }
        cout << endl;

        // Here b is de-allocated since its scope is ending
    }

    cout << "The vector a now contains: " << endl;
    for(unsigned int i = 0; i < a.size(); i++){
        cout << a[i] << " ";
    }
    cout << endl;

    cout << "A vector of strings contains: ";
    MyVector<string> v;
    v.push_back("Hello");
    v.push_back("world!");
    for (unsigned int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}
