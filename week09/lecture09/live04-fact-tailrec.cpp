// Recursive implementation of factorial in different styles
#include <iostream>
using namespace std;

// Recursive factorial (standard)
unsigned int fact(unsigned int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * fact(n-1);
    }
}

// Recursive factorial (tail recursive using accumulator 'acc')
unsigned int fact_tailrec(unsigned int n, unsigned int acc = 1) {
    if (n == 0) {
        return acc;
    }
    return fact_tailrec(n-1, n*acc);
}

int main() {
    unsigned int n;

    // Try with with big numbers, e.g. 1000000
    // Compare compilation with and without optimization (g++ option -O3)
    cout << "Give me a non-negative double: " ;
    cin >> n;
    cout << "Computing fact_tail(" << n << ")... " << fact_tailrec(n) << endl;
    cout << "Computing fact(" << n << ")... " << fact(n) << endl;

    return 0;
}
