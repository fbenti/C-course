#include "BankAccount.h"
#include <iostream>

using namespace std;

//constructor
BankAccount::BankAccount(int number, string owner, double balance) {
    // to refer to the bank account I'm referring on I can use 'this'
    // it's a point to the current instances of the object
    this->number = number;
    this->owner = owner;
    this->balance = balance;
}

BankAccount::~BankAccount() {
    cout << "** The bank account " << this->owner << " is being destroyed" << endl;
} 


double BankAccount::getBalance() const {
    return balance;
}

int BankAccount::getNumber() const {
    return number;
}

const string BankAccount::getOwner() const {
    return owner;
}

void BankAccount::print() const {
    cout << "Account number " << number << " owned by " << owner << " contains " << balance << endl;
}

bool BankAccount::transferMoney(BankAccount &to, double value) {
    if(value < 0 || balance < value){
        cout << "Transfer failed" << endl;
        return false;
    } else {
        balance -= value;
        to.balance += value;
        cout << "Transfer succeeded" << endl;
        return true;
    }
}

bool BankAccount::wrongTransferMoney(BankAccount to, double value) {
    if(value < 0 ||balance < value){
        cout << "Transfer failed" << endl;
        return false;
    }
    else{
        balance-=value;
        to.balance += value;
        cout << "Transfer succeeded" << endl;
        return true;
    }
}

bool BankAccount::withdraw(double value) {
    if(value < 0 ||balance < value){
        return false;
    } else {
        balance-=value;
        return true;
    }
}

bool BankAccount::deposit(double value) {
    balance += value;
    return true;
}
