// Example of stack overflow
#include <iostream>
using namespace std;

void f(unsigned int depth) {
    // int a[10000]; // Uncomment this line to accelerate the stack overflow
    cout << "Stack depth " << depth << " reached!" << endl;

    f(depth + 1);
}

int main() {
    f(0);

    return 0;
}
