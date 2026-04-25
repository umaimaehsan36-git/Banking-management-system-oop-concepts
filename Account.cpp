#include "Account.h"

Account::Account() {
    balance = 0;
}

void Account::setBalance(double b) {
    balance = b;
}

double Account::getBalance() {
    return balance;
}

void Account::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
    }
}

bool Account::withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        return true;
    }
    return false;
}