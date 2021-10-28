//============================================================================
// Name        : live02-MyVector.cpp
// Description : My own vector implementation
//============================================================================

#include <iostream>
#include "MyVector.h"

using namespace std;

int main(void){

    // We declare a MyVector a
    MyVector a;

    cout << "The initial size is: " <<  a.size() << endl;

    // We insert some numbers with push_back
    for (unsigned int i=0; i < 20; i++) {
        a.push_back(i);
    }
    cout << "After the insertions the size is: " <<  a.size() << endl;

    cout <<"[] "<< a[15] << endl;
    cout <<"at "<< a.at(15) << endl;

    cout << "We access elements in array-style or using 'at': " << endl;
    for(unsigned int i = 0; i < a.size(); i++){
    		cout << a.at(i) << " " << a.at(i) << endl;
    }
    cout << endl;

    // We open a new scope
    {
        MyVector b;
        // if we don't overload the operator = , here we just operate the classical copy
        // copying the context of a into b (size, capacity and also pointer to the arrray
        // that contains the data) : so now a and b have both a pointer to the same array
        // So here, we use b, and when the scope ends the destructor of b delete the shared array
        // but a will still point to it, so we get random data. Then at the end of the second scope
        // also the a deconstructor is called which again delete the same array, so we get error free() double 
        // free detected..

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
}
