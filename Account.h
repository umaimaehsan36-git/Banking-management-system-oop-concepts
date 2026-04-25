#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account {
private:
    double balance;

public:
    Account();
    void setBalance(double b);
    double getBalance();

    void deposit(double amount);
    bool withdraw(double amount);
};

#endif