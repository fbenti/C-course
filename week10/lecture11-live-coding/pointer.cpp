#include <iostream>
using namespace std;

void increment_all (int* start, int* stop){
    int * current = start;
    while (current != stop) {
        ++(*current);  // increment value pointed
        ++current;     // increment pointer
    }
}

void print_all (const int* start, const int* stop) {
// void print_all (int* start,int* stop)
    const int * current = start;
    while (current != stop) {
        cout << *current << '\n';
        ++current;     // increment pointer
    }
}

int addition (int a, int b)
{ return (a+b); }

int subtraction (int a, int b)
{ return (a-b); }

int operation (int x, int y, int (*functocall)(int,int))
{
  int g;
  g = (*functocall)(x,y);
  return (g);
}

int main() {
    /* Pointer inizialization*/
    int myvar = 10;
    int * myptr = &myvar; // When pointers are initialized, what is initialized is the address they point to 
                          // (i.e., myptr), never the value being pointed (i.e., *myptr).
    cout << "Value " << *myptr << " at location " << myptr << endl; 

    int myvar1;
    int *myptr1;
    myptr1 = &myvar1;

    /* CONST
     it is also possible to declare pointers that can access the pointed value to read it, but not to modify it. */
    int x;
    int y = 15;
    // Note that the expression &y is of type int*, but this is assigned to a pointer of type const int*. 
    // This is allowed: a pointer to non-const can be implicitly converted to a pointer to const, but not the opposite
    const int * p = &y; // &y is called POINTER to y of type int
    cout << "Value " << *p << " at location " << p << endl;  // i can read it
    // *p = x;  // but not modify its

    // One of the use cases of pointers to const elements is as function parameters: a function that takes a pointer 
    // to non-const as parameter can modify the value passed as argument, while a function that takes a pointer to const as parameter cannot.
    int numbers[] = {10,20,30};
    increment_all (numbers,numbers+3);
    print_all (numbers,numbers+3);


    /* POINTERS TO POINTERS */
    char a;
    char * b;
    char ** c;
    a = 'z';
    b = &a;
    c = &b;

    cout << "Char " << a << " at location " << &b << endl;
    cout << "Char " << *b << " at location " << &b << endl;
    cout << "Char " << **c << " at location " << &c << endl;

    // cout << "c contain " << c << " which is equal to " << &b << endl;
    

    /* POINTERS TO FUNCTIONS */ 
    int m,n;
    int (*minus)(int,int) = subtraction;
    m = operation (7, 5, addition);
    n = operation (20, m, minus);
    // n = operation (20, m, subtraction);
    cout << "add " << m << endl;
    cout << "minus " << n << endl;

    return 0;
}