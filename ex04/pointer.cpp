#include <iostream>
#include <string> 
using namespace std;

int main() 
{
    int x  = 5;

    int *p = nullptr;
    p= &x;

    cout << p << endl;
    cout << *p << endl;

    cout << &x << endl;
    return 0;
}