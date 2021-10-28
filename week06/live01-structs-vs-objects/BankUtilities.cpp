#include "BankUtilities.h"
#include <iostream>

using namespace std;

bool transferMoney(BankAccountStruct &from, BankAccountStruct &to, double value) {
    if (value < 0 || from.balance < value){
        cout << "Transfer failed" << endl;
        return false;
    } else {
        from.balance-=value;
        to.balance+=value;
        cout << "Transfer succeeded" << endl;
        return true;
    }
}

void printAccount(const BankAccountStruct &acc){
    cout << "Account number " << acc.number << " owned by " << acc.owner << " contains " << acc.balance << endl;
}
