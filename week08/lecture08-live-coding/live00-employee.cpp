//============================================================================
// Name        : live00-employee.cpp
// Description : Basic inheritance
//============================================================================

#include <iostream>
#include <string>

using namespace std;

class Employee {
public: // what is shared between the employees
    string name;
};

class HourlyEmployee: public Employee { // inherit Emplyee in a public way, so everything that is public in A remains public in B
public:
    HourlyEmployee(string n) { this->name = n; } // this namefield exist beacuase we are inheriting from Employee
    double hourlyFee;
};

class CommissionedEmployee: public Employee {
public:
    CommissionedEmployee(string n) { this->name = n; }
    double commission;
};

class SalariedEmployee: public Employee {
public:
    SalariedEmployee(string n) { this-> name = n; }
    double salary;
};

int main(void) {
    HourlyEmployee h = HourlyEmployee("Alice");
    CommissionedEmployee c = CommissionedEmployee("Bob");
    SalariedEmployee s = SalariedEmployee("Carol");

    cout << "The employee names are: ";
    cout << h.name << ", " << c.name << ", " << s.name << endl;

    return 0;
}
