// Example with templated functions
#include <iostream>
#include <string>

using namespace std;

// This is a templated function.
// The template has a parameter T, which is a type.
// This function template takes two values of type T as input
// and returns a value of type T
template<class T>
T average(T x, T y) {
    return (x + y) / 2 ;
}

// This is another example of templated function taking a type T as argument.
// Using 'typename' (as in here) or 'class' (as above) is equivalent.
template<typename T>
T safe_average(T x, T y) {
    return (x + y) / 2 ;
}

// Templated functions can be specialised for some cases.
// Here we are specialising safe_average() for when its arguments are ints
template<>
int safe_average<int>(int x, int y) {
    if ((x + y) % 2 != 0) cout << "*** WARNING! Truncating values! *** ";
    return (x + y) / 2 ;
}

// Here we are specialising safe_average() for when its arguments are strings
// We don't need to repeat the class typo because the compiler knows that we are extending an already defined templeate
template<>
string safe_average<string>(string x, string y) {
    return to_string(safe_average<double>(stod(x), stod(y))) ;
}

int main(void) {
    double d1 = 1.0;
    double d2 = 2.0;
    int i1 = 1;
    int i2 = 2;
    string s1 = "1.0";
    string s2 = "2.0";

    // These are examples of using the templated function average
 
    // With doubles...
    cout << "The average between " << d1 << " and " << d2 << " is... ";
    cout << average<double>(d1, d2) << endl;

    // ...and with integers
    cout << "The average between " << i1 << " and " << i2 << " is... ";
    cout << average<int>(i1, i2)<< endl;

    // Here we use a specialized variant of the templated function
    cout << "The safe_average between " << i1 << " and " << i2 << " is... ";
    cout << safe_average<int>(i1, i2)<< endl;

    // And here we try to do the average of strings
    cout << "The safe_average between " << s1 << " and " << s2 << " is... ";

    // Uncommenting the line below leads to a compilation error:
    // this is because division is not defined for strings
    // cout << average<string>(s1, s2) << endl;

    // The line below is OK because the templated function has a specialization
    // for strings which does not use division
    cout << safe_average<string>(s1, s2)<< endl;

    return 0;
}
