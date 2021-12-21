// Efficient computation of (a^n) mod p
// Try compiling with and without the g++ option -O3
#include <iostream>
#include <chrono>
using namespace std;

// Iterative version
int exp(int a, int n, int p) {
    int result;
    
    result = 1;
    for (int i = 0; i < n; i++) {
       result = (result * a) % p;
    }
    return result;
}

int exp_rec0(int a, int n, int p) {
    if (n == 0) return 1;
    return a * exp_rec0(a, n-1, p) % p;
}

//  Recursive version
int exp_rec(int a, int n, int p) {
    if (n == 0) return 1;
    if (n%2 == 0){
        return (exp_rec(a, n/2, p) * exp_rec(a, n/2, p)) % p;
    }
    return (a * exp_rec(a, n-1, p)) % p;
}

// Recursive version with some memoization (i.e., caching of results)
int exp_rec_memo(int a, int n, int p) {
    if (n == 0) return 1;
    if (n%2 == 0){
        int i = exp_rec_memo(a, n/2, p);
        return (i * i) % p;
    }
    return (a * exp_rec_memo(a, n-1, p)) % p;
}

int main() {
    int a, n, p;

    a = 3;
    n = 100000000;
    p = 3523;

    std::chrono::high_resolution_clock::time_point t1;
    std::chrono::high_resolution_clock::time_point t2;

    t1 = std::chrono::high_resolution_clock::now();
    cout << "Computing " << a << "^" << n << " modulo " << p << " recursively (with memo)... "
    << exp_rec_memo(a,n,p) << endl;
    t2 = std::chrono::high_resolution_clock::now();
    cout << "It took " << std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count() << " ms" << endl;

    t1 = std::chrono::high_resolution_clock::now();
    cout << "Computing " << a << "^" << n << " modulo " << p << " recursively... "
         << exp_rec(a,n,p) << endl;
    t2 = std::chrono::high_resolution_clock::now();
    cout << "It took " << std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count() << " ms" << endl;

    t1 = std::chrono::high_resolution_clock::now();
    cout << "Computing " << a << "^" << n << " modulo " << p << " iteratively... "
         << exp(a,n,p) << endl;
    t2 = std::chrono::high_resolution_clock::now();
    cout << "It took " << std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count() << " ms" << endl;
}

