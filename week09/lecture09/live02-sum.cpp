// Sum of arithmetic series 1..n, i.e. 1+..+n
#include <iostream>
using namespace std;

// Smart implementation by Carl Friedrich Gauss (1777-1855) :-)
unsigned int sum_fast(unsigned int n){
    return (n * (n + 1)) / 2 ;
}

// Iterative implementation
unsigned int sum_iter(unsigned int n){
    unsigned int sum = 0;
    for (unsigned int i = 1; i <= n; i++) {
        sum += i;
    }
    return sum;
}

// A possible recursive implementation
// could be a problem when we have lot of recurisive calls
// -> try to pass as argument to the compiler -O3
// g++ -O3 liveo2-sum.cpp -o live02-sum.exe
// this optimization is called TAIL_CALL OPTIMIZATION
unsigned int sum_rec(unsigned int n) {
    if (n == 0) {
        return 0;
    } else {
        return n + sum_rec(n-1);
    }
}

// It is possible to implement recursive function in machine code by using a constant amounnt of
// stack space, essentially turning them into loops. So the last thing that a function must do
// is either return a value or the result of a recursive call. -> using an accumulator

// An alternative implementation using an accumulator argument (acc)
//
// Note that this function is in "tail recursive" format: it either returns a
// value (without recursion), or directly returns the result of a
// recursive call.  Functions like this enable very efficient code
unsigned int sum_rec_tailcall(unsigned int n, unsigned int acc = 0) { //default value in c++
    if (n == 0) {
        return acc; // acc has the current sum 
    }
    return sum_rec_tailcall(n-1, n+acc); // we just return the value of the recursive call
    // not a n operation!
} //it's still a recursive call, because we still have a base case, and in the recursive call we still 
// pass a smaller instance of the problem.

// A key difference between sum_rec and sum_rec_tailcall is that in sum_rec the last thing that
// happen in the return case is an operation, which means that every time the function call itself it needs to preserve the stack
// Instead, in sum_rec_tailcall, in the return I directly return the result of the recursive call, that means we don't need to
// remember the current invocation and just overwrite the stack with the new values.


int main(){
    unsigned int n;

    // Try with with big numbers, e.g. 1000000
    // Compare compilation with and without optimization (g++ option -O3)
    cout << "Give me a non-negative integer: " ;
    cin >> n;
    cout << "Computing sum(1.." << n << ") using sum_fast... ";
    cout << sum_fast(n) << endl;
    cout << "Computing sum(1.." << n << ") using sum_iter... ";
    cout << sum_iter(n) << endl;
    cout << "Computing sum(1.." << n << ") using sum_rec_tailcall... ";
    cout << sum_rec_tailcall(n) << endl;
    cout << "Computing sum(1.." << n << ") using sum_rec... ";
    cout << sum_rec(n) << endl;

    return 0;
}
