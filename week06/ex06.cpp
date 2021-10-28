#include <iostream>
#include <string>
#include "Fraction.h"

using namespace std;

int main(void){

    while(true) {
        int a,b,c,d;
        char op1;
        string op2;
        
        cin >> a;
        if (cin.fail()) {
            break;
        }
        cin >> op1;
        if (cin.fail()) {
            break;
        }
        cin >> b;
        if (cin.fail()) {
            break;
        }
        cin >> op2;
        if (cin.fail()) {
            break;
        }
        cin >> c;
        if (cin.fail()) {
            break;
        }
        cin >> op1;
        if (cin.fail()) {
            break;
        }
        cin >> d;
        if (cin.fail()) {
            break;
        }

        fraction f1(a,b);
        fraction f2(c,d);

        if (op2 == "+")
            f1.add(f2);
        else if (op2 == "*")
            f1.mult(f2);
        else
            f1.div(f2);

        f1.display();
    }
}