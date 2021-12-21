// Simple recursive implementation of factorial
#include <iostream>
using namespace std;

unsigned int fact(unsigned int n) {
    if (n == 0) {
        cout << "    fact(" << n << ") = 1.  End of recursion!" << endl ;
        return 1;
    } else {
        cout << "    fact(" << n << ") = " << n << " * fact(" << n-1 << ") " << endl;
        double ret = n * fact(n-1);
        cout << "    returning fact(" << n << ") = " << ret << endl;
        return ret;
    }
}

int main() {
    unsigned int n;
    
    cout << "Please enter a non-negative number: " ;
    cin >> n;
    cout << "Computing fact(" << n << ")... " << endl;
    unsigned int result = fact(n);
    cout << "The result is: " << result << endl;

    return 0;
}

// What happen if we call fact(10000000) -> each loop it call itself recursively, expanding the stack
// and at some point we get the error: segmentaion fault
// -> the compiler can be smart enough to do not reallocate the stack every time we do a recursive call
// and the trick is to optimize the code, with a flag -O3
