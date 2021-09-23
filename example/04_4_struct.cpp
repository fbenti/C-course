// Example showing how to use 'struct'ures
#include <iostream>
#include <string>
using namespace std;

// Is a user-defined data type that combines values of different types
struct employee {  // this definition is global
    string name;
    string surname;
    unsigned int salary;
};

/**
 * This function takes a constant pointer to an employee structure.
 * This way, we avoid copying the structure contents, and the compiler will
 * ensure that the function does not modify it.
 * NOTE: since we use a struct pointer, we write e->field instead of e.field
 *
 * Exercise: redefine the function to use references instead of pointers
 */
void displayEmployee(const employee *e) {
    cout << "Name: " << e->name << "; surname: " << e->surname;
    cout << "; salary: " << e->salary << endl;
}

int main() {
    employee e1 = {"Bjarne", "Stroustrup", 100000}; // Initialised structure
    
    employee e2; // Uninitialised structure.  We initialise its fields below
    e2.name = "Margaret";
    e2.surname = "Hamilton";
    e2.salary = 500000;

    displayEmployee(&e1);
    displayEmployee(&e2);

    // defining p as a pointer to an employee giving the address of e1
    // to access the pointer value (*p).name or p->name
    employee *p = &e1;
    cout << p->name << " or " << (*p).surname << endl;
    return 0;
}
